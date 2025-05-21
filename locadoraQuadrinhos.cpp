// Locadora de HQs

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void descobreExperiencia();
void surpreender();
void sorteiaQuadrinhos();
void realizaAluguel();
string descobrePreferenciaUser();
void recomendaQuadrinhos(string preferencia);
void exibirCarrinho(); 

string preferenciaUser;
string nomeUser;
string carrinho[5]; 
int quantidadeCarrinho = 0;

const int TAM_SORTEIO = 10;
const int TAM_ACERVO = 20;

int indicesSorteados[TAM_SORTEIO];
string acervoQuadrinhos[TAM_ACERVO] = {
    // Marvel (da lista sorteada)
    "Marvels (1994)",
    "Civil War (2006–2007)",
    "Infinity Gauntlet (1991)",
    "X-Men: Days of Future Past (1981)",
    "Daredevil: Born Again (1986)",

    // Marvel (novas)
    "House of M (2005)",
    "Secret Wars (2015)",
    "Planet Hulk (2006)",
    "Spider-Man: Blue (2002)",
    "Old Man Logan (2008)",

    // DC (da lista sorteada)
    "Watchmen (1986–1987)",
    "The Dark Knight Returns (1986)",
    "Kingdom Come (1996)",
    "Batman: Year One (1987)",
    "All-Star Superman (2005–2008)",

    // DC (novas)
    "Batman: The Killing Joke (1988)",
    "The Flash: Rebirth (2009)",
    "Green Lantern: Sinestro Corps War (2007)",
    "Justice League: Tower of Babel (2000)",
    "Superman: Red Son (2003)"
};

string quadrinhosSorteados[TAM_SORTEIO] = {
    // Marvel
    "Marvels (1994)",
    "Civil War (2006–2007)",
    "Infinity Gauntlet (1991)",
    "X-Men: Days of Future Past (1981)",
    "Daredevil: Born Again (1986)",

    // DC Comics
    "Watchmen (1986–1987)",
    "The Dark Knight Returns (1986)",
    "Kingdom Come (1996)",
    "Batman: Year One (1987)",
    "All-Star Superman (2005–2008)"
};

int main() {
    descobreExperiencia();
    realizaAluguel();
    exibirCarrinho(); // exibe carrinho no final
    return 0;
}

void descobreExperiencia() {
    char experiencia;
    cout << "Olá, qual o seu nome? ";
    cin >> nomeUser;

    cout << "\nSeja bem-vindo(a) à loja de HQs!\n";
    cout << "\nPara começarmos, você já conhece sobre HQs? Digite 'S' para sim e 'N' para não: ";
    cin >> experiencia;
    experiencia = toupper(experiencia);

    while (experiencia != 'S' && experiencia != 'N') {
        cout << "\nPor favor, insira o formato válido de 'S' para sim e 'N' para não: ";
        cin >> experiencia;
        experiencia = toupper(experiencia);
    }

    if (experiencia == 'S') {
        preferenciaUser = descobrePreferenciaUser();
        recomendaQuadrinhos(preferenciaUser);
    } else {
        surpreender();
    }
}

void surpreender() {
    char resposta;
    cout << "\n\nVocê gostaria de ser surpreendido(a)? Posso recomendar um HQ aleatório tanto da Marvel como da DC Comics, duas editoras muito boas de quadrinhos! \nDigite 'S' para sim e 'N' para não: ";
    cin >> resposta;
    resposta = toupper(resposta);

    if (resposta == 'S') {
        sorteiaQuadrinhos();
    } else {
        preferenciaUser = descobrePreferenciaUser();
        recomendaQuadrinhos(preferenciaUser);
    }
}

void sorteiaQuadrinhos() {
    srand(time(0));
    int contador = 0;

    cout << "\nVocê pode gostar de:\n";

    while (contador < TAM_SORTEIO) {
        bool repetido = false; 
        int indice = rand() % TAM_SORTEIO;

        for (int i = 0; i < contador; i++) {
            if (indicesSorteados[i] == indice) {
                repetido = true;
                break;
            }
        }

        if (!repetido) {
            cout << contador + 1 << ". " << quadrinhosSorteados[indice] << endl;
            indicesSorteados[contador] = indice;
            contador++;
        }
    }
}



string descobrePreferenciaUser() {
    while (true) {
        cout << "\nVocê prefere as HQs da editora DC Comics ou da Marvel? ";
        cin >> preferenciaUser;

        for (int i = 0; i < preferenciaUser.length(); i++) {
            preferenciaUser[i] = toupper(preferenciaUser[i]);
        }

        if (preferenciaUser == "DC" || preferenciaUser == "MARVEL") {
            return preferenciaUser;
        } else {
            cout << "\nOpção inválida!\n ";
        }
    }
}

void recomendaQuadrinhos(string preferenciaUser) {
    cout << "\nCerto! Aqui estão as opções disponíveis da editora " << preferenciaUser << ":\n";

    if (preferenciaUser == "MARVEL") {
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". " << acervoQuadrinhos[i] << endl;
        }
    } else if (preferenciaUser == "DC") {
        for (int i = 10; i < 20; i++) {
            cout << i - 9 << ". " << acervoQuadrinhos[i] << endl;
        }
    }
}

void realizaAluguel() {
    char resposta;

    do {
        if (quantidadeCarrinho >= 5) {
            cout << "\n\nATENÇÃO! Seu carrinho está cheio com 5 HQs. Finalizando o aluguel.\n";
            break;
        }

        cout << "\nDeseja alugar alguma HQ? Digite 'S' para sim e 'N' para não: ";
        cin >> resposta;
        resposta = toupper(resposta);

        if (resposta != 'S') {
            break;
        }

        int escolhaHq;
        cout << "Digite o número da HQ que você deseja (1 a 10): ";
        cin >> escolhaHq;

        if (escolhaHq < 1 || escolhaHq > 10) {
            cout << "Número inválido. Tente novamente.\n";
            continue;
        }

        int indice = -1;
        if (preferenciaUser == "MARVEL") {
            indice = escolhaHq - 1;
        } else if (preferenciaUser == "DC") {
            indice = escolhaHq + 9;
        }

        string hqEscolhida = acervoQuadrinhos[indice];
        carrinho[quantidadeCarrinho] = hqEscolhida;
        quantidadeCarrinho++;


        int escolhaSemanas;
        cout << "\nPor quantas semanas deseja alugar esse quadrinho?\n";
        cout << "1 Semana -> R$ 20" << endl;
        cout << "2 Semanas -> R$ 35" << endl;
        cout << "3 Semana -> R$ 45" << endl;
        cin >> escolhaSemanas;

        switch (escolhaSemanas) {
            case 1:
                cout << "Você alugou por 1 semana.  Caso precise, pode estender o prazo para mais 2 semanas.\n";
                break;
            case 2:
                cout << "Você alugou por 2 semanas.  Caso precise, pode estender o prazo para mais 1 semana.\n";
                break;
            case 3:
                cout << "Você alugou por 3 semanas. Não é possível estender o prazo.\n";
                break;
            default:
                cout << "Não alugamos HQs para esse prazo!.\n";
                quantidadeCarrinho--;
                continue;
        }

    } while (true);

    if (quantidadeCarrinho == 0) {
        cout << "Que pena, " << nomeUser << "! Volte sempre para ver novas recomendações.\n";
    } else {
        cout << "Muito obrigado, " << nomeUser << "! Suas HQs foram adicionadas ao carrinho.\n";
    }
}


void exibirCarrinho() {
    if (quantidadeCarrinho > 0) {
        cout << "\n\nVocê alugou " << quantidadeCarrinho << " quadrinho(s)!";
        cout << "\nO pagamento será efetuado na devolução das HQs. Boa leitura!\n";
    }
}
