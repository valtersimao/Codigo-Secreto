# 🔐 Código Secreto

Trabalho Prático da disciplina **Introdução à Programação** desenvolvido em **C**.

O projeto implementa um jogo inspirado em **Mastermind**, no qual o jogador deve descobrir uma sequência secreta de cores utilizando as dicas fornecidas após cada tentativa.

---

## 📖 Sobre o projeto

O programa gera uma sequência secreta de cores e, a cada tentativa do jogador, informa:

- ✅ Quantas cores estão na posição correta;
- 🟡 Quantas cores existem na sequência, mas estão na posição errada;
- ❌ Quantas cores não pertencem à sequência.

O jogo também permite salvar partidas, carregar jogos anteriormente salvos e manter um ranking das melhores pontuações.

---

## ✨ Funcionalidades

- 🎮 Novo jogo
- 💾 Salvar partida
- 📂 Carregar partida
- 🏆 Sistema de ranking
- 📜 Histórico das tentativas
- 🎨 Interface colorida utilizando códigos ANSI
- 📖 Menu de ajuda
- ⚙️ Diferentes níveis de dificuldade

---

## 📁 Estrutura do projeto

```
.
├── Codigo-Secreto.c      # Arquivo principal (main)
├── Jogo.c                # Lógica do jogo
├── Jogo.h
├── Ranking.c             # Sistema de ranking
├── Ranking.h
├── Utilidades.c          # Funções auxiliares
├── Utilidades.h
├── ranking.rnk           # Arquivo binário do ranking
├── *.cor                 # Arquivos de cores/salvamento
└── Extras/
    └── Trabalho_Pratico_V3.pdf
```

---

## 🧠 Conceitos utilizados

Durante o desenvolvimento foram aplicados diversos conceitos de programação em C, como:

- Structs
- Ponteiros
- Alocação dinâmica de memória
- Matrizes dinâmicas
- Manipulação de arquivos binários
- Modularização do código
- Separação em arquivos `.c` e `.h`
- Vetores
- Geração de números aleatórios
- Manipulação de strings

---

## ▶️ Como compilar

### Linux (GCC)

```bash
gcc Codigo-Secreto.c Jogo.c Ranking.c Utilidades.c -o codigo-secreto
```

Executar:

```bash
./codigo-secreto
```

---

### Windows (MinGW)

```bash
gcc Codigo-Secreto.c Jogo.c Ranking.c Utilidades.c -o codigo-secreto.exe
```

Executar:

```bash
codigo-secreto.exe
```

---

## 🎮 Como jogar

1. Execute o programa.
2. Escolha **Novo Jogo**.
3. Selecione a dificuldade.
4. Digite sua sequência de cores.
5. Utilize as informações fornecidas para descobrir o código secreto.
6. Caso deseje, salve a partida para continuar posteriormente.

---

## 🏆 Ranking

O jogo mantém um ranking das melhores partidas.

As informações são armazenadas no arquivo:

```
ranking.rnk
```

O ranking considera:

- Nome do jogador
- Nível de dificuldade
- Quantidade de tentativas

---

## 💾 Salvamento

O estado completo da partida pode ser salvo em arquivo, incluindo:

- Nome do jogador
- Dificuldade
- Sequência secreta
- Histórico de jogadas
- Número de tentativas

Assim é possível continuar exatamente do ponto em que o jogo foi interrompido.

---

## 🎨 Interface

O projeto utiliza códigos ANSI para colorir a saída do terminal, tornando a visualização das cores e das informações do jogo mais intuitiva.

---

## 📚 Objetivos acadêmicos

Este trabalho teve como objetivo praticar:

- Organização de projetos em múltiplos arquivos
- Manipulação de memória
- Arquivos binários
- Desenvolvimento modular
- Estruturas de dados básicas
- Boas práticas em linguagem C

---

## 👨‍💻 Autor

**Valter dos Santos Simão Júnior**

Disciplina: **Introdução à Programação**

Universidade Federal de Ouro Preto (UFOP)

---

## 📄 Licença

Projeto desenvolvido exclusivamente para fins acadêmicos.
