// Locadora de HQs

#include <iostream>
#include <cstime>
#include <cstdlib>
using namespace std;
void descobreExperiencia();
void surpreender();
string nomeUser;
char experiencia;

int main()
{
    descobreExperiencia();

    return 0;
}

void descobreExperiencia(){
    cout << "Olá, qual o seu nome? ";
    cin >> nomeUser;
    
    cout << "Seja bem-vindo(a) à loja de HQs!\n";
    cout << "\nPara comerçarmos, você já conhece sobre HQs? Digite 'S' para sim e 'N' para não: ";
    cin >> experiencia;
    experiencia = toupper(experiencia);
    
    while (experiencia != 'S' && experiencia != 'N'){
        cout << "\nPor favor, insira o formato válido de 'S' para sim e 'N' para não: ";
        cin >> experiencia;
        experiencia = toupper(experiencia);
    }
    
    
    if (experiencia == 'S'){
        cout << "Você prefere as HQs da DC Comics ou Marvel?";
    } else{
        surpreender(experiencia);
    }
}

void surpreender(){
    cout << "Você gostaria de ser surpreendido(a)? Posso recomendar um HQ aleatório tanto da Marvel como da DC Comics, duas empresas muito boas de quadrinhos! ";
    cin >> respostaSurpreender;
    
}
