# 📚 Sistema Acadêmico

Projeto aplicado em **C** para praticar structs, funções, vetores, validação de dados e organização de um programa de forma modularizada, além do versionamento com Git e GitHub.

O sistema simula o gerenciamento de turmas e alunos por um professor, permitindo o uso de múltiplas funções. Este projeto está finalizado e o histórico detalhado de alterações está em [changelogs.txt](changelogs.txt).

## 📄 Funcionalidades atuais

- Cadastro de professor, com validação de ID, idade e preenchimento de dados;
- Gerenciamento de turmas: cadastro, edição, acesso, exclusão e definição de avaliações;
- Gerenciamento de alunos por turma: cadastro, edição, listagem, busca, exclusão;
- Gerenciamento de notas dos alunos: lançamento de notas, edição, visualização de boletim e estatísticas da turma;
- O sistema possui validações para os dados e regras de negócio implementadas, mas ainda existem limitações no tratamento de entradas inválidas.

## ❗ Limites atuais

- Os dados ficam apenas na memória durante a execução, ao encerrar o programa, eles não são salvos;
- Falta de tratamento de erros para entradas inválidas, o que quebra o código se for executado com entradas inválidas.
- Valores decimais nas avaliações podem, em casos raros, ser rejeitados por arredondamento, e um aluno com nota exatamente igual à média pode ser reprovado;
- Alterar o valor das avaliações, a média da turma ou redefinir as avaliações zera as notas já lançadas.

## 📐 Regras

| Item | Regra |
| :--- | :--- |
| **Quantidade** | Até 10 turmas, 35 alunos por turma e 5 avaliações por turma |
| **Professor** | ID com 4 dígitos (1000 a 9999) e idade mínima de 21 anos |
| **Turma** | Série de 1 a 9; turno com **uma única palavra** (Matutino, Vespertino ou Noturno), até 14 caracteres; matéria com até 39 caracteres |
| **Aluno** | Matrícula com 6 dígitos (100000 a 999999) e única dentro da turma; nome com até 79 caracteres |
| **Avaliações** | Cada valor maior que 0 e até 10; a soma de todas deve ser exatamente 10; nome com até 34 caracteres |
| **Média da turma** | Maior que 0 e menor que 10 |
| **Notas** | De 0 até o valor da avaliação correspondente |
| **Aprovação** | O aluno é aprovado quando a soma das notas é maior ou igual à média da turma |
| **Zerar notas** | Alterar o **valor** de uma avaliação, a **média da turma** ou **redefinir** as avaliações zera as notas já lançadas da turma, e é preciso lançá-las novamente. Alterar só o **nome** de uma avaliação mantém as notas |
| **Encerramento** | Ao sair do menu de turmas, o programa é encerrado e os dados são perdidos |

## 🖋️ Conceitos praticados

- Structs e vetores em C;
- Modularização por arquivos .c e .h;
- Operações CRUD para turmas e alunos;
- Validação de dados e regras de negócio;
- Manipulação e ordenação de dados;
- Git, branches, commits e histórico de alterações.

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
5. Obtenha o projeto conforme a seção [Como obter o projeto](#como-obter-o-projeto). Como o Git foi instalado no passo anterior, a opção recomendada é:

   ```bash
   git clone https://github.com/gabrielramoss32/Academic-System.git
   cd Academic-System
   ```

6. Compile e execute:

   ```bash
   gcc src/*.c -Iinclude -o sistema
   ./sistema.exe
   ```
Siga as instruções apresentadas pelo programa.

## ⏯️ Compilação e execução com MinGW-w64 já instalado

Se o comando `gcc --version` já funciona no PowerShell, primeiro obtenha o projeto conforme a seção [Obter o projeto](#obter-o-projeto). Depois, abra o PowerShell dentro da pasta `Academic-System` e execute:

```powershell
gcc src/*.c -Iinclude -o sistema
```

O comando gera o executável `sistema.exe`.

```powershell
.\sistema.exe
```

Após isso, o projeto irá iniciar, siga as opções apresentadas no terminal. Para explorar o gerenciamento de alunos, cadastre ou acesse uma turma e selecione a opção correspondente no menu.

## 🗂️ Estrutura

```text
Academic-System/
├── include/                         # Cabeçalhos (.h): structs, constantes e protótipos das funções
│   ├── cadastro_turma.h             # Struct Turma, limites MAX_TURMAS e MAX_ALUNOS, variáveis globais das turmas
│   ├── gerenciamento_aluno.h        # Struct Aluno, limite MAX_AVALIACOES e funções de alunos
│   ├── gerenciamento_avaliacoes.h   # Funções de avaliações e o vetor av_cadastrada
│   ├── gerenciamento_notas.h        # Struct Classificacao e funções de notas, boletim e estatísticas
│   ├── gerenciamento_turma.h        # Funções de acesso, edição e exclusão de turmas
│   ├── menu.h                       # Função do menu inicial
│   └── professor_cadastro.h         # Struct Professor e função de cadastro do professor
├── src/                             # Implementação (.c)
│   ├── main.c                       # Ponto de entrada do programa
│   ├── menu.c                       # Menu inicial
│   ├── professor_cadastro.c         # Cadastro do professor
│   ├── cadastro_turma.c             # Cadastro de turmas e menu de turmas
│   ├── gerenciamento_turma.c        # Acesso, edição e exclusão de turmas
│   ├── gerenciamento_aluno.c        # Menu e gerenciamento de alunos
│   ├── gerenciamento_avaliacoes.c   # Definição, edição e listagem das avaliações
│   └── gerenciamento_notas.c        # Lançamento de notas, boletim e estatísticas
├── .gitignore                       # Ignora build, sistema.exe e .vscode
├── changelogs.txt                   # Histórico oficial de versões e alterações
└── README.md                        # Documentação geral do projeto
```

## 📆 Possíveis melhorias

A versão atual foi compilada e testada no Windows com **GCC 15.2.0 (MinGW-W64)**. Peço que ao encontrar quaisquer erros indesejados no projeto, entre em contato com o proprietário para correção.

- Futuras melhorias:
1. Integração com ponteiros e memória dinâmica;
2. Tratamento adequado para entradas inválidas;
3. Implementar persistência dos dados por meio de arquivos ou de um banco de dados SQL.