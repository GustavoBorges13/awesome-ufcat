import os
import urllib.parse
import sys

BLACKLIST = ['.git', '.github', 'scripts', 'venv', 'README.md', 'CONTRIBUTING.md', 'LICENSE', 'update_readme.py', 'docs', 'ufcat_logo.png']

def gerar_arvore(caminho_base='.'):
    arvore_md = ""
    disciplinas = sorted([d for d in os.listdir(caminho_base) if os.path.isdir(os.path.join(caminho_base, d)) and d not in BLACKLIST])
    
    for disciplina in disciplinas:
        link_disciplina = urllib.parse.quote(disciplina)
        arvore_md += f"- [{disciplina}]({link_disciplina})\n"
        
        # Entra na pasta da disciplina para pegar as subpastas (Prova 1, Prova 2...)
        caminho_disciplina = os.path.join(caminho_base, disciplina)
        subpastas = sorted([sub for sub in os.listdir(caminho_disciplina) if os.path.isdir(os.path.join(caminho_disciplina, sub))])
        
        for subpasta in subpastas:
            # Monta o link juntando Disciplina/Subpasta sem quebrar as barras
            link_subpasta = f"{urllib.parse.quote(disciplina)}/{urllib.parse.quote(subpasta)}"
            # Adiciona 4 espaços no começo para criar a sub-lista (bullet list aninhada)
            arvore_md += f"    - [{subpasta}]({link_subpasta})\n"
            
        arvore_md += "\n" # Pula uma linha entre as matérias para ficar mais bonito
        
    return arvore_md.strip()

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
            "\n" + conteudo[fim:]
        )
        with open('README.md', 'w', encoding='utf-8') as f:
            f.write(novo_conteudo)
    else:
        print("❌ ERRO: Marcadores <!-- INICIO_LISTA --> e <!-- FIM_LISTA --> não encontrados no README.md!")
        sys.exit(1)

if __name__ == '__main__':
    arvore = gerar_arvore()
    atualizar_readme(arvore)
