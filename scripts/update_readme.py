import os

# Pastas e arquivos que o script deve ignorar
BLACKLIST = ['.git', '.github', 'scripts', 'venv', 'README.md', 'CONTRIBUTING.md', 'LICENSE', 'update_readme.py']

def gerar_arvore(caminho_base='.'):
    arvore_md = "## 📚 Lista de Disciplinas\n\n"
    
    # Pega apenas as pastas das disciplinas, em ordem alfabética
    disciplinas = sorted([d for d in os.listdir(caminho_base) if os.path.isdir(d) and d not in BLACKLIST])
    
    for disciplina in disciplinas:
        arvore_md += f"### {disciplina}\n"
        tipos_prova = sorted(os.listdir(f"{caminho_base}/{disciplina}"))
        
        for tipo in tipos_prova:
            caminho_tipo = f"{caminho_base}/{disciplina}/{tipo}"
            if os.path.isdir(caminho_tipo):
                # Codifica os espaços para links do GitHub funcionarem
                link = f"{disciplina}/{tipo}".replace(" ", "%20")
                arvore_md += f"- [{tipo}]({link})\n"
        
        arvore_md += "\n"
        
    return arvore_md

def atualizar_readme(texto_arvore):
    # Lemos o README atual
    with open('README.md', 'r', encoding='utf-8') as f:
        conteudo_antigo = f.read()

    # Marcadores onde o script vai injetar a lista (Adicione isso no seu README!)
    marcador_inicio = "<!-- INICIO_LISTA -->"
    marcador_fim = "<!-- FIM_LISTA -->"

    inicio = conteudo_antigo.find(marcador_inicio)
    fim = conteudo_antigo.find(marcador_fim)

    if inicio != -1 and fim != -1:
        novo_conteudo = (
            conteudo_antigo[:inicio + len(marcador_inicio)] + 
            "\n" + texto_arvore + 
            conteudo_antigo[fim:]
        )
        with open('README.md', 'w', encoding='utf-8') as f:
            f.write(novo_conteudo)
        print("✅ README.md atualizado com sucesso!")
    else:
        print("❌ Marcadores <!-- INICIO_LISTA --> e <!-- FIM_LISTA --> não encontrados no README.md.")

if __name__ == '__main__':
    arvore = gerar_arvore()
    atualizar_readme(arvore)