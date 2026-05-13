#!/usr/bin/python

"""
Adaptacao do codigo de exemplo
linuxrouter.py: Example network with Linux IP router
~mininet/examples/linuxrouter.py

"""

from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import Node
from mininet.log import setLogLevel, info
from mininet.cli import CLI

class LinuxRouter( Node ):
    "A Node with IP forwarding enabled."

    def config( self, **params ):
        super( LinuxRouter, self).config( **params )
        # Enable forwarding on the router
        self.cmd( 'sysctl net.ipv4.ip_forward=1' )

    def terminate( self ):
        self.cmd( 'sysctl net.ipv4.ip_forward=0' )
        super( LinuxRouter, self ).terminate()


class NetworkTopo( Topo ):
    "A LinuxRouter connecting three IP subnets"

    def build( self, **_opts ):

        defaultIP = '192.168.1.1/24'  # IP address for r0-eth1
        router = self.addNode( 'r0', cls=LinuxRouter, ip='192.168.1.1/24' )
        r2     = self.addNode( 'r2', cls=LinuxRouter, ip='10.1.0.2/16' )

        s1, s2, s3, s4, s5 = [ self.addSwitch( s ) 
                               for s in 's1', 's2', 's3', 's4', 's5' ]

        self.addLink( s1, router, intfName2='r0-eth1',
                      params2={ 'ip' : defaultIP } )  # for clarity
        self.addLink( s2, router, intfName2='r0-eth2',
                      params2={ 'ip' : '172.16.0.1/12' } )
        self.addLink( s3, router, intfName2='r0-eth3',
                      params2={ 'ip' : '10.0.0.1/16' } )
        self.addLink( s4, router, intfName2='r0-eth4',
                      params2={ 'ip' : '10.1.0.1/16' } )
        self.addLink( s4, r2, intfName2='r2-eth1',
                      params2={ 'ip' : '10.1.0.2/16' } )
        self.addLink( s5, r2, intfName2='r2-eth2',
                      params2={ 'ip' : '10.2.0.1/16' } )

        h1 = self.addHost( 'h1', ip='192.168.1.100/24',
                           defaultRoute='via 192.168.1.1' )
        h2 = self.addHost( 'h2', ip='172.16.0.100/12',
                           defaultRoute='via 172.16.0.1' )
        h3 = self.addHost( 'h3', ip='10.0.0.100/16',
                           defaultRoute='via 10.0.0.1' )
        h4 = self.addHost( 'h4', ip='10.2.0.44/16',
                            defaultRoute='via 10.2.0.1' )

        for h, s in [ (h1, s1), (h2, s2), (h3, s3), (h4, s5) ]:
            self.addLink( h, s )


def run():
    "Test linux router"
    topo = NetworkTopo()
    net = Mininet( topo=topo )  # controller is used by s1-s3
    net.start()
    info( '*** Routing Table on Router:\n' )
    print net[ 'r0' ].cmd( 'route' )
    CLI( net )
    net.stop()

if __name__ == '__main__':
    setLogLevel( 'info' )
    run()
