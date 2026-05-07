# 🤝 Como Contribuir com o Awesome UFCAT

Sua contribuição ajuda toda a comunidade da universidade! Siga os passos abaixo para enviar materiais:

### 🛑 PASSO 1: Oculte seus dados pessoais
Antes de qualquer coisa, **remova seu nome, matrícula ou assinatura** da prova. 
Para facilitar, criamos uma ferramenta oficial e 100% segura (roda offline no seu navegador):
👉 **[Acesse o Editor de Provas Awesome UFCAT](https://GustavoBorges13.github.io/awesome-ufcat/)**

### 📁 PASSO 2: Organize as pastas
Verifique se a disciplina e o tipo de prova já existem. Se não, crie seguindo esta regra:
- **Disciplina:** Nome sem acentos, com espaços. Números em algarismos romanos. (Ex: `Engenharia de Software II`)
- **Tipo de Prova:** Crie uma subpasta com opções como: `Prova 1`, `Prova 2`, `Prova 3`, `Reposicao`, `Final`.

### 📄 PASSO 3: Renomeie o arquivo
O arquivo deve estar em `.pdf`, `.jpg` ou `.png` e seguir o padrão: `<ano>_<semestre>.extensão`

| Situação | Exemplo de Nome |
|----------|-----------------|
| Prova padrão | `2023_1.pdf` |
| Mais de uma prova no mesmo semestre | `2023_1(1).pdf` e `2023_1(2).pdf` |
| Várias imagens da mesma prova | `2023_1-pag1.jpg` e `2023_1-pag2.jpg` |
| Ano ou semestre desconhecido | `20XX_1.pdf` ou `202X_X.pdf` |
| Disciplina de outro curso (Ex: Física) | `2018_1_fisica.pdf` |

> ⚠️ **Atenção:** Nosso robô (GitHub Actions) fiscaliza os nomes dos arquivos. Se o nome estiver fora do padrão, ele não vai deixar o arquivo ser aceito!

---

### 🚀 PASSO 4: Como enviar
Escolha a opção que for mais fácil para você:

#### Opção A (Mais fácil - Sem GitHub)
Envie o arquivo diretamente pelo nosso [Formulário do Google](#) *(link em breve)* ou para o e-mail `coloqueseuemail@ufcat.edu.br`.

#### Opção B (Via GitHub Issues)
Se você tem conta no GitHub, mas não quer mexer com código: 
Vá na aba **Issues**, clique em "New Issue", arraste e solte o seu PDF lá dentro, escreva de qual matéria é e clique em *Submit*. Nós baixamos e organizamos para você!

#### Opção C (Para Devs - Via Fork & Pull Request)
Quer colocar uma contribuição Open-Source no seu currículo? Usamos o fluxo profissional com a branch `dev`. Siga este passo a passo:

**1. Faça o Fork:**
Clique no botão **"Fork"** no canto superior direito desta página para criar uma cópia do repositório no seu GitHub pessoal. Certifique-se de incluir a branch `dev`.

**2. Clone para o seu computador:**
Abra o terminal e baixe o **seu** repositório (Substitua `SEU-USUARIO` pelo seu nick do GitHub):
```bash
git clone https://github.com/SEU-USUARIO/awesome-ufcat.git
cd awesome-ufcat
```

**3. Vá para a branch `dev` e crie a sua Branch:**
Nós sempre testamos as provas na branch `dev` antes de ir para a principal. Mude para ela e crie a sua branch de trabalho:
```bash
git checkout dev
git checkout -b adiciona-provas-calculo
```

**4. Adicione os arquivos e faça o Commit:**
Coloque os PDFs nas pastas corretas, e depois salve:
```bash
git add .
git commit -m "feat: adiciona provas de Calculo I e Fisica 3"
```
> 💡 **Dica:** Não se preocupe em editar o arquivo `README.md`! Nosso robô atualiza a lista de disciplinas automaticamente assim que sua prova for aprovada.

**5. Envie para o seu GitHub (Push):**
```bash
git push origin adiciona-provas-calculo
```

**6. Abra o Pull Request (PR) para a `dev`:**
Vá até a página original do `awesome-ufcat`. O GitHub vai mostrar uma faixa amarela com um botão verde escrito **"Compare & pull request"**. 
⚠️ **Atenção aqui:** Na tela de criar o PR, certifique-se de que a *base branch* (o repositório de destino) esteja apontando para **`dev`** (e não `main`). Deixe um comentário dizendo de qual matéria é e clique em "Create pull request". 

Pronto! Nossos robôs revisores vão analisar seu arquivo na `dev` e logo ele estará disponível para todos os alunos. 🎉
