#include "../include/shell.h"

void launch_shell(int n){
	int aff;
	string ch = (string) malloc(200);
	do{
        print("B.OS (");
        print(int_to_string(n));
        print(")> ");
        ch = readStr();
		aff = strEql(ch,"help");
		print(int_to_string(aff));
        print(ch);
        if(strEql(ch,"cmd")){
            print("\nVoce ja esta no no cmd. Novo shell recursivo aberto\n");
            launch_shell(n+1);
        }
        else if(strEql(ch,"clear"))
            clearScreen();
        else if(strEql(ch,"sum"))
            sum();
        else if(strEql(ch,"exit"))
            print("\nAte mais!\n");
        else if(strEql(ch,"echo"))
            echo();
        else if(strEql(ch,"sort"))
            sort();
        else if(strEql(ch,"fibo"))
            fibonaci();
        else if(strEql(ch,"help"))
            help();
        else if(strEql(ch,"color"))
            set_bg_color();
        else{
            print("\nDesconhecido!\n");
        } 
	} while (!strEql(ch,"exit"));
}

void sum(){
    int n, i, s;
	print("\nQuantos numeros: ");
	n = str_to_int(readStr());
	i = 0;
	print("\n");
	int arr[n];
	fill_array(arr,n);
	s = sum_array(arr,n);
	print("Resultado: ");
	print(int_to_string(s));
	print("\n");
}

void fill_array(int arr[],int n){
	int i;
	for (i = 0;i<n;i++){
		print("ARR[");
		print(int_to_string(i));
		print("]: ");
		arr[i] = str_to_int(readStr());
		print("\n");
	}
}

void print_array(int arr[],int n){
	int i;
	for (i = 0;i<n;i++){
		print(int_to_string(arr[i]));
		print("   ");
	}
	print("\n");
}

int sum_array(int arr[],int n){
	int i, s = 0;
	for (i = 0;i<n;i++)
		s += arr[i];
	return s;
}

void echo(){
	print("\n");
	string str = readStr();
	print("\n");
	print(str);
	print("\n");
}

void sort(){
	int arr[100];
	print("\nTamanho do vetor: ");
	int n = str_to_int(readStr());
	print("\n");
	fill_array(arr,n);
	print("Antes:\n");
	print_array(arr,n);
	print("\nOrdem: (1 - Crescente | 0 - Decrescente): ");
	int order = str_to_int(readStr());
	insertion_sort(arr,n,order);
	print("\nDepois:\n");
	print_array(arr,n);
}

void insertion_sort(int arr[],int n,int order){
	int i;
	for (i = 1;i<n;i++){
		int aux = arr[i];
		int j = i;
		while((j > 0) && ((aux < arr[j-1]) && order )){
			arr[j] = arr[j-1];
			j = j -1;
		}
		arr[j] = aux;
	}
}

void fibonaci(){
    int i, n;
	print("\nQuantidade de elementos: ");
	n = str_to_int(readStr()); 
	print("\n");
	for(i = 0; i < n; i++){
		print("Fibo ");
		print(int_to_string(i));
		print(" : ");
		print(int_to_string(fibo(i)));
		print("\n");
	}
}

int fibo(int n){
	if(n <2)
		return 1;
	else 
		return fibo(n-1) + fibo(n-2);
}

void set_bg_color()
{
	print("\nCodigo de cores : ");
	print("\n0 : black");
	print_colored("\n1 : azul",1,0);   // screen.h
	print_colored("\n2 : verde",2,0);
	print_colored("\n3 : ciano",3,0);
	print_colored("\n4 : vermelho",4,0);
	print_colored("\n5 : purpura",5,0);
	print_colored("\n6 : laranja",6,0);
	print_colored("\n7 : cinza",7,0);
	print_colored("\n8 : cinza escuro",8,0);
	print_colored("\n9 : azul claro",9,0);
	print_colored("\n10 : verde claro",10,0);
	print_colored("\n11 : azul mais claro",11,0);
	print_colored("\n12 : vermelho claro",12,0);
	print_colored("\n13 : rosa",13,0);
	print_colored("\n14 : amarelo",14,0);
	print_colored("\n15 : branco",15,0);
	
	print("\n\n Cor do texto: ");
	int text_color = str_to_int(readStr());
	print("\n\n Cor de fundo: ");
	int bg_color = str_to_int(readStr());
	set_screen_color(text_color,bg_color);
	clearScreen();
}

void help(){
	print("\ncmd       : Novo Shell recursivo");
	print("\nclear     : Limpa a tela");
	print("\nsum       : Computa a soma de n numeros");
	print("\necho      : Imprime um dado texto");
	print("\nsort      : Ordena n numeros");
	print("\nfibonaci  : Imprime os n primeiros numeros da Serie de Fibonacci");
    print("\ncolor     : Muda a cor do terminal");
	print("\nexit      : Sai do shell atual");
	
	print("\n\n");
}

