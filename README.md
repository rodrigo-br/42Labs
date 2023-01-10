<details>
	<summary>Subject</summary>

# Labs 4º Edição

## Desafio

O desafio consiste no desenvolvimento de uma aplicação de análise e compressão de dados. Essa aplicação utilizará o algoritmo de compressão Huffman e poderá receber múltiplos dados onde, uma vez que comprimido deve ser descomprimido e coletar informações pertinentes para a análise do processo e dado.

Para isso, você criará dois programas: `encoder` e `decoder`. O encoder receberá o dado a ser comprimido e exibirá suas informações vindas do decoder. Já, o decoder descomprimirá o dado e irá enviá-lo ao encoder com suas informações, onde será exibido. Os programas devem se comunicar utilizando *shared memory operations*.

A linguagem C será utilizada para o desenvolvimento e não há bibliotecas externas permitidas.

## É necessário

- Que existam dois programas `encoder` e `decoder` que se comuniquem via memória compartilhada.
- Que o `encoder` possa receber, no mínimo, múltiplos textos como dado e comprimi-lo. Caso mais de um texto seja enviado, devem ser comprimidos juntos, resultando em apenas um único dado.
- Que o algoritmo de Huffman seja implementando em sua totalidade e que o processo de compressão e descompressão ocorram utilizando-o.
-  Que o `decoder` possa descomprimir e enviar as seguintes informações ao `encoder`: dado descomprimido, quantidade de bits ou bytes totais, quantidade de bits ou bytes comprimidos e o tempo da operação de descompressão.
- O `encoder` exibir as informações recebidas pelo `decoder`.

### O que será avaliado

- Código bem escrito e limpo.
- A documentação do seu código.
- Ferramentas que foram utilizadas e por quê.
- Sua criatividade e capacidade de lidar com problemas diferentes.
- Alinhamento do seu projeto com a proposta.

### O mínimo necessário

- README.md com a documentação contendo informações do projeto.

### Bônus

Os itens a seguir não são obrigatórios, mas são funcionalidades que darão mais valor ao seu desafio.

- Compressão de múltiplos arquivos binários.
- Criptografia do dado comprimido, utilizando senha fornecida pelo usuário.
- Verificação de integridade do arquivo comprimido.
- Opção para escolher mais outro algoritmo de compressão a ser utilizado.
- Tempo de descompressão (`decoder`) abaixo da média dos candidatos.
- Cuidados especiais com otimização e padrões de código.
- Uso de ferramentas externas para planejamento nas etapas de desenvolvimento.

<sub><sup>[Importante](https://xkcd.com/1381/)</sup></sub>
</details>

## Fase 1 - Estudo

A fim de compreender do que se trata o projeto, os desafios que irei
enfrentar e o aprendizado pendente necessário para completar a tarefa,
fui em busca de conteúdos rápidos já disponíveis sobre o assunto.
Minhas fontes de pesquisa iniciais foram:


Essa playlist no YouTube: [Algoritmo de Huffman em C](https://www.youtube.com/watch?v=o8UPZ_KDWdU&list=PLqJK4Oyr5WShtxF1Ch3Vq4b1Dzzb-WxbP)


Este livro: [Programação em C++ - Algoritmos e Estrututas de Dados](https://a.co/d/0LGtXRI)


## Fase 2 - Construção das principais estruturas de dados

### 2.1 Huffman's Tree

Resolvi começar pelo básico, e apenas construir as principais estruturas
que eu vi necessidade, iniciando pela Árvore Huffman.
Para isso, faz-se necessário o uso de uma lista de ponteiros para nós
da árvore. O algoritmo de construção da árvore se descreve nos seguintes
passos:

- Analisar a mensagem a compactar;

- Registrar em uma *tabela* o número de ocorrências de cada símbolo;

- Criar um nó para cada símbolo, constituído por um atributo que identifique
o *símbolo* e outro com o *número de ocorrências* do mesmo;

- Inserir os ponteiros para nós em uma lista, em ordem crescente, ordenados
pelo *número de ocorrências*;

- Recursivamente, criar um nó intermediario, realizando as seguintes ações:

	- Remover os dois ponteiros iniciais;
	- Iniciar left e right do nó criado os ponteiros
	removidos;
	- Iniciar o atributo *número de ocorrências* com
	a soma dos atributos *número de ocorrências* dos
	nós left e right por ele apontados;
	- Inserir ordenadamente na lista o apontador para o nó criado, ordenados pelo *número de ocorrências*;

- Quando a lista tiver apenas um ponteiro, este ponteiro apontará para a raiz da Árvore.


Os nós intermediários não recebem nenhum valor significativo no atributo
*símbolo*.

Logo, para criar a Árvore Huffman, nota-se a necessidade de criar uma tabela de ocorrência dos símbolos.
Após a criação da tabela, inicio a lista de nós e faço a ordenação dos mesmos.

Agora que tenho a estrutura da árvore montada, só criar algumas funções para criar a árvore, seguindo os passos acima e a árvore fica prontinha.


### 2.2 Map

Próxima estrutura a ser criada é um mapa dos symbolos e seus
respectivos códigos. Como em uma árvore, os percursos da raiz para qualquer uma das *folhas* (Nós onde os dois descendentes, left e right, são nulos) são únicos, a codificação e a descodificação dos códigos têm sempre uma árvore associada.