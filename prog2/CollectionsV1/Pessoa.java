public class Pessoa{
    private String nome;
    private int idade;
    public Pessoa(String nome, int idade){
        this.nome = new nome;
        this.idade = new idade;
    }
    // @Override
    // public String toString(){
    //     return("Nome: " + this.nome + " Idade: " this.idade);
    // }

    // @Override
    // public int compareTo(Pessoa p){

    // }

    public String getNome(){
        return nome;
    }
    public int getIdade(){
        return idade;
    }
}