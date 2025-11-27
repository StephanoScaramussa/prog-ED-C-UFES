//nao pode haver outra classe externa publica
//classe externa nunca pode ser privada
public class AlunoDeGraduacao{  //classe nao declara com parenteses
    public class interna; //excecao
    private String nome; //variavel de instancia, variavel de referencia, guarda um ponteiro que aponta para a classe String, inicializa com NULL
    private int matricula; //variavel de instancia(declarada dentro do corpo da classe) variavel primitiva, guarda um valor
    private double nota1,nota2; //inicializa com valor default do tipo dela
    //-atributo (privado) private
    //+atributo (publico) public
    //~atributo (pacote)
    //#atributo (protegido) protected
    // /atributo (derivado) nao e variavel, e um metodo
    //-----
    //operacoes
    public double calcularMedia(){//metodo
        double soma = nota1 + nota2;//so sao declaradas se receberem variaveis de instancia, nao sao inicializadas
        double media = soma/2;
        return media;
        //variaveis de pilha ou locais, cada chamada de funcao cria uma pagina de pilha com suas variaveis, so existem no stack durante a execucao do metodo
    }//metodos implementam operacoes de uma classe
}

//objetos ficam na heap, eles que tem a informacao das variaveis na memoria
//java nao tem lixo de memoria

// class Lorem{

// }
//cada classe tera um arquivo fonte, nao ha mais de uma por arquivo
//pilha de execucao stack
AlunoDeGraduacao[] pessoas = new AlunoDeGraduacao[x];
AlunoDeGraduacao alunoStephano = new AlunoDeGraduacao(); //objeto criado com uma variavel apontando para o mesmo, usando o new
int[] numeros = new int[5]; //todo vetor e um objeto, ja esta totalmente inicializado, vetor primitivo
for (int i=0;i<numeros.length;i++){
    System.out.printIn(numeros[i]);
}
for (int i=0;i<numeros.length;i++){
    numeros[i]=10;
}
String pessoa1 = "Bruno";
String pessoa2 = "Bruno";
System.out.printIn(pessoa1.equals(pessoa2));