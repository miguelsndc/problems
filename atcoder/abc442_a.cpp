#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ja_avisei_vai_dar_merda_isso_ai() {
    string s; cin >> s;
    int ic = count(s.begin(), s.end(), 'i');
    int jc = count(s.begin(), s.end(), 'j');
    cout << ic + jc;
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) ja_avisei_vai_dar_merda_isso_ai();
}

// pare antes de submitar pra revisar, antes -5 minutos revisando do q -10 de um wa
// escreve no papel e fala em voz alta imbecil; Escreve o somatorio no papel e tenta simplificar
//
// dp; contagem = total - complementar; da pra achar um greedy via exchange argument?; bitset; casa dos pombos
// da pra manter um multiset/set/prorityqueue dos otimos? se puder sortar sorte!; sweep line
// sorta por abertura/fechamento dos intervalos!; invariantes: paridade, soma, mod
// bs na resposta; chute a dp; convex hull trick; sempre tentar tirar um log onde der
// da pra fazer algo randomizado; cheesar com alguma estrutura bizarra ? olha pra gauss se a dp tiver uns ciclos
// olha bit a bit; olha a fatoração prima; gcd apenas diminui, lcm apenas aumenta, apenas log distintos gcd/lcm,
// lcm é o maximo de cada fator, gcd o minimo de cada fator comum; max log primos distintos na fatoracao; prime gaps
// if(x>=MOD) x-=MOD sempre que der; trie pra xor min/max; hash pra comparar substrings
// inverte tempo das queries; constroi ao inves de destruir, dsu, d&c; small to large
// CDQ, d&c, Mo's/sqrt merge sort tree / sorta queries se offline
// d&c faz o merge o minimo de vezes, constante melhor q seg; segtree ou bit
// grafo implícito? DAG? functional graph? grafo de permutação (ciclos)?
// binlift se monoid (el.neutro+transitivo) toposort antes de dp
// dp na árvore / dfs / centroid / lca / euler tour; fluxo? abre dinic na lib
// olha edge cases: n=0/1, overflow antes do cast, k>n, todos iguais, input já ordenado, n=MOD
// self-loop, multigrafo, componente isolado, query vazia, i=j, resposta negativa/zero