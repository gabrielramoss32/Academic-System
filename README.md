# 📚 Sistema Acadêmico

Aplicação de console em **C** para praticar estruturas, funções, vetores, validação de dados e organização de um programa em múltiplos arquivos.

O sistema simula o gerenciamento de turmas e alunos por um professor. Este projeto está em desenvolvimento; o histórico detalhado de alterações está em [changelogs.txt](changelogs.txt).

## 📄 Funcionalidades atuais

- Cadastro de professor, com validação de ID e idade;
- Gerenciamento de turmas: cadastro, edição, acesso e exclusão;
- Gerenciamento de alunos por turma: cadastro, edição, listagem e exclusão;
- Busca de aluno por matrícula ou por nome;
- Validação de matrícula com seis dígitos e prevenção de matrículas duplicadas na mesma turma.

## ❗ Limites atuais

- Até 10 turmas e 35 alunos por turma;
- Os dados ficam apenas na memória durante a execução: ao encerrar o programa, eles não são salvos;
- A busca de alunos ainda está sendo revisada, especialmente para nomes com acentos e buscas por parte do nome;
- As opções de notas, boletim e estatísticas já aparecem no menu, mas ainda não foram implementadas.

## 💻 Requisitos

- Windows 10 (versão 1809 ou mais recente) de 64 bits;
- Um compilador C compatível com GCC/MinGW-w64.

## 📌 Como obter o projeto

Você precisa ter uma cópia do projeto no computador antes de compilá-lo. Escolha **uma** das opções abaixo:

### 🛡️ 1. Opção recomendada: Git

Se o Git estiver instalado, abra um terminal na pasta onde deseja guardar o projeto e execute:

```bash
git clone https://github.com/gabrielramoss32/Academic-System.git
cd Academic-System
```

Não é necessário baixar nem extrair um arquivo ZIP: o `git clone` já baixa os arquivos e cria a pasta `Academic-System`.

### 🗃️ 2. Alternativa: arquivo ZIP

Na página do repositório, clique em **Code** e depois em **Download ZIP**. Em seguida, extraia o arquivo e abra um terminal dentro da pasta extraída `Academic-System`.

## ▶️ Primeira execução: sem compilador instalado

Se você nunca programou em C ou ainda não possui um compilador, siga estes passos. Eles usam o [MSYS2](https://www.msys2.org/), que é um ambiente de desenvolvimento para Windows que fornece um terminal e ferramentas como Git e GCC/MinGW-w64, permitindo compilar e executar projetos em C.

1. Baixe e instale o [MSYS2](https://www.msys2.org/), mantendo a pasta de instalação sugerida.
2. Ao concluir, abra o terminal **MSYS2 UCRT64**. Ele já configura o compilador para uso nesse terminal, não é necessário editar o `PATH` do Windows.
3. Instale o GCC e o Git digitando o comando abaixo e pressionando `Enter`. Quando for solicitada confirmação, pressione `Enter` novamente para aceitar a opção padrão, a instalação pode levar alguns minutos.

   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc git
   ```

4. Confirme que a instalação funcionou:

   ```bash
   gcc --version
   ```

   Se aparecer uma versão do GCC, o compilador está pronto.
5. Obtenha o projeto conforme a seção [Obter o projeto](#obter-o-projeto). Como o Git foi instalado no passo anterior, a opção recomendada é:

   ```bash
   git clone https://github.com/gabrielramoss32/Academic-System.git
   cd Academic-System
   ```

6. Compile e execute:

   ```bash
   gcc src/*.c -Iinclude -o sistema
   ./sistema.exe
   ```

## ⏯️ Compilação e execução com MinGW-w64 já instalado

Se o comando `gcc --version` já funciona no PowerShell, primeiro obtenha o projeto conforme a seção [Obter o projeto](#obter-o-projeto). Depois, abra o PowerShell dentro da pasta `Academic-System` e execute:

```powershell
gcc src/*.c -Iinclude -o sistema
```

O comando gera o executável `sistema.exe`.

```powershell
.\sistema.exe
```

Siga as opções apresentadas no terminal. Para explorar o gerenciamento de alunos, cadastre ou acesse uma turma e selecione a opção correspondente no menu.

## 🗂️ Estrutura

```text
Academic-System/
├── include/             # Arquivos de cabeçalho e estruturas do sistema
├── src/                 # Implementação dos menus e funcionalidades
├── changelogs.txt       # Histórico autoritativo do projeto
└── README.md
```

## 📆 Estado do projeto

A versão atual foi compilada e testada no Windows com **GCC 15.2.0 (MinGW-W64)**. O fluxo de cadastro de turma, cadastro/listagem de aluno e busca por nome foi executado com sucesso durante essa verificação.

Próximos passos incluem finalizar e refatorar a busca de alunos, implementar o gerenciamento de notas e adicionar persistência de dados.
