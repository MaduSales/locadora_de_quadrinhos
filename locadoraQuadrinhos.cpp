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

string preferenciaUser;
string nomeUser;
char respostaSurpreender;
char experiencia;

const int TAM_SORTEIO = 10;
const int TAM_ACERVO = 20;

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
    

int main()
{
    descobreExperiencia();
    realizaAluguel();

    return 0;
}

void descobreExperiencia(){
    cout << "Olá, qual o seu nome? ";
    cin >> nomeUser;
    
    cout << "\nSeja bem-vindo(a) à loja de HQs!\n";
    cout << "\nPara comerçarmos, você já conhece sobre HQs? Digite 'S' para sim e 'N' para não: ";
    cin >> experiencia;
    experiencia = toupper(experiencia);
    
    while (experiencia != 'S' && experiencia != 'N'){
        cout << "\nPor favor, insira o formato válido de 'S' para sim e 'N' para não: ";
        cin >> experiencia;
        experiencia = toupper(experiencia);
    }
    
    
    if (experiencia == 'S'){
        preferenciaUser = descobrePreferenciaUser();
        recomendaQuadrinhos(preferenciaUser);
        
    } else{
        surpreender();
    }
}

void surpreender(){
    cout << "\nVocê gostaria de ser surpreendido(a)? Posso recomendar um HQ aleatório tanto da Marvel como da DC Comics, duas editoras muito boas de quadrinhos! ";
    cin >> respostaSurpreender;
    respostaSurpreender = toupper(respostaSurpreender);
    
    if (respostaSurpreender == 'S'){
        sorteiaQuadrinhos();
    } else{
        preferenciaUser = descobrePreferenciaUser();
        recomendaQuadrinhos(preferenciaUser);
    }
    
}

void sorteiaQuadrinhos(){
    srand(time(0));
    
    cout << "\nVocê pode gostar de:\n";
    for (int i = 0; i < TAM_SORTEIO; i++) {
        int indice = rand() % TAM_SORTEIO;
        cout << i + 1 << ". " << quadrinhosSorteados[indice] << endl;
    }
}


string descobrePreferenciaUser(){
    while (true){
        cout << "\nVocê prefere as HQs da editora DC Comics ou da Marvel? ";
        cin >> preferenciaUser;
        
        
        // Convertendo a string inteira para letras maiúsculas
        for (int i = 0; i < preferenciaUser.length(); i++) {
            preferenciaUser[i] = toupper(preferenciaUser[i]); 
        }
        
        
        if (preferenciaUser == "DC" || preferenciaUser == "MARVEL"){
            return preferenciaUser;
        } 
        else{
            cout << "\nOpção inválida!\n ";
            continue;
        }
    }
}


void recomendaQuadrinhos(string preferenciaUser){
    cout << "\nCerto! Aqui estão algumas sugestões da editora " << preferenciaUser << ":\n";

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


void realizaAluguel(){
    cout << "\nDeseja realizar a compra de alguma HQ? Digite 'S' para sim e 'N' para não: ";
    char resposta;
    cin >> resposta;
    resposta = toupper(resposta);

    if (resposta == 'S') {
        int escolha;
        cout << "Digite o número da HQ que você deseja (1 a 10): ";
        cin >> escolha;

        if (escolha >= 1 && escolha <= 10) {
            cout << "\nCompra realizada com sucesso! Você escolheu: " << acervoQuadrinhos[escolha - 1] << endl;
        } else {
            cout << "Número inválido. Nenhuma compra realizada.\n";
        }
    } else {
        cout << "Tudo bem," << nomeUser <<"! Volte sempre para ver novas recomendações.\n";
    }
}
