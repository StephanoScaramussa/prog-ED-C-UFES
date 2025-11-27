public class Pessoa{
    private String nome;
    private int idade;

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    public String getIdade(){
        return idade;
    }

    public void setIdade(int idade){
        this.idade = idade;
    }
    public void exibirDados(){
        System.out.printIn("Nome: " + nome + " Idade: " + idade)
    }
}

public class TestaPessoa{
    public static void main(String[], args){
        Pessoa p1 = new Pessoa();
        p1.setNome("Joao");
        p1.setIdade(16);
        p1.exibirDados();
    }
}