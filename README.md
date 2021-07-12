# Mem-ria-e-Disco
Trabalho de Algoritmo e Estruturas de Dados, Centro Federal de Educação Tecnológica de Minas Gerais

Em um computador há diferentes arquivos, e esses só podem ser carregados para a memória
de forma parcial (pense grande, há muitos dados). Como a memória não é infinita, de tempos
em tempos parte desses arquivos precisarão ser devolvidos para o disco para liberar espaço para novas partes. Para isso o computador adota a seguinte estratégia: Um processo Pk
solicita uma ordem/sequência de leitura das partes de acordo com um arquivo de configuração.
Arquivo esse definido no seguinte padrão hP1, 04, 07, 01, 01, 08, 06, ...., 03i.
A sequência de páginas de um processo é buscada em disco e enviada para a memória,
a qual as organiza em ordem de chegada. Quando o espaço de memória que aloca as partes
do arquivo do processo Pk estiver cheia, ou seja, com 5 partes, uma parte será devolvida para
o disco. Como regra, a parte enviada para disco sempre será a mais antiga solicitada, ou seja,
a que chegou primeiro dentre as 5.
Quando uma parte do arquivo é solicitada por um processo, pode-se ocorrer uma de duas
condições: 1) - A parte já está em memória, logo, não há essa mesma página em disco. Logo,
apenas a utilizamos e computamos como acesso válido de memória; 2) - A parte não está em
memória e precisa ser removida do disco e transportada para a memória. Nesse caso, computamos como falha de leitura e executamos o procedimento de carregamento dessa página
para a memória, retirando-a do disco. A Figura 1 detalha o modelo de simulador a ser construído.


Problema a ser resolvido: Elaborar um código estruturado em C/C++ que consiga simular
as condições descritas. Considere para isso estabelecer um arquivo de entrada/configuração
cujas linhas representam processos e chamadas de partes de um arquivo conforme exemplo
detalhado no primeiro parágrafo. Junto a isso, considere um segundo arquivo que detalhe M
arquivos e a ordem de suas partes conforme exemplo: hA1, 03, 02, 05, 01, 04i. Observe que
o arquivo de configuração define o arquivo A1 com 5 partes e a ordem de suas partes está
definida conforme o exemplo. Assim, sua função é emular todo esse sistema com esses dois
arquivos de entrada pré-definidos. Por fim, detalhar quantos erros de leitura ocorreram e quantas leituras de memória bem sucedidas ocorreram por processo. Por fim, sugerir uma forma
melhor de organizar a memória que reduza a quantidade de falhas durante a execução. Mostre
em relatório qual é a porcentagem de ganho que sua solução apresenta em comparação com
a solução básica implementada.




--------------------------------------------------------------------Relatório Final de Conclusão------------------------------------------------------------------------------
Aluno: Leonardo de Oliveira Campos
Professor: Michel
CENTRO FEDERAL DE EDUCAÇÃO TECNOLÓGICA DE MINAS GERAIS

Comecei a desenvolver o software com linguagem C++, o qual achava ser mais fácil desenvolvimento, ledo engano. Contanto como já havia dado inicio na programação, continuei com tal linguagem de programação. Implementei um swite case para fazer um menu que dá acesso as diversas funcionalidades do software, funcionalidades dentro do escopo do trabalho. Hodiernamente, terminei o trabalho finalizando a questão das memórias de disco, no qual havia a demanda por trocar a informação dos arquivos conforme fosse requisitado pelo usuário. Concluindo com sucesso tal etapa, que consistia retirar informações especificas de um arquivo, denominado Disco para outro arquivo, denominado Memória, no qual era instruido pelo arquivo Processos para levar informações localizadas nas casas específicadas pelo professor. Por fim, desse processo, o usuário teria a chance de limpar a memória novamente para reuso. O qual ocorreu com sucesso. Assim, foi simulado o funcionamento da memória. Quanto ao ganho no processo de estabilidade de memória, o método que desenvolvi ao longo do código, presando pela utilização de funções, não houve uma sequência mutua de erros, visto que o encaixe da programação por meio da arquitetura a que cheguei deixou a leitura do arquivo e sua manipulação estáveis e de fácil manutenção futura, por se tratar de funções, os erros são encontrados e tratados facilmente. Obviamente na modelagem de tal script houve falhas, entretanto, após a conclusão da escrita do código, os erros foram suprimidos de campo. O software em questão, por fim, obteve 0% de erro, após a conclusão da programação.

