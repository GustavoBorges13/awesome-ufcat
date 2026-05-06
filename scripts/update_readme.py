import os

BLACKLIST = ['.git', '.github', 'scripts', 'venv', 'README.md', 'CONTRIBUTING.md', 'LICENSE', 'update_readme.py', 'docs', 'ufcat_logo.png']

def gerar_arvore(caminho_base='.'):
    arvore_md = ""
    disciplinas = sorted([d for d in os.listdir(caminho_base) if os.path.isdir(d) and d not in BLACKLIST])
    
    for disciplina in disciplinas:
        link = disciplina.replace(" ", "%20")
        arvore_md += f"- [{disciplina}]({link})\n"
        
    return arvore_md

def atualizar_readme(texto_arvore):
    with open('README.md', 'r', encoding='utf-8') as f:
        conteudo = f.read()

    marcador_inicio = "<!-- INICIO_LISTA -->"
    marcador_fim = "<!-- FIM_LISTA -->"

    inicio = conteudo.find(marcador_inicio)
    fim = conteudo.find(marcador_fim)

    if inicio != -1 and fim != -1:
        novo_conteudo = (
            conteudo[:inicio + len(marcador_inicio)] + 
            "\n" + texto_arvore + 
            conteudo[fim:]
        )
        with open('README.md', 'w', encoding='utf-8') as f:
            f.write(novo_conteudo)

if __name__ == '__main__':
    arvore = gerar_arvore()
    atualizar_readme(arvore)