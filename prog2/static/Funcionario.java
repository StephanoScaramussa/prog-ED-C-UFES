public class Funcionario{
    private String nome;
    private static Funcionario instancia = null;

    private Funcionario(String nome){
        this.nome = nome;
    }

    public static void criaInstancia(String nome){
        if(Funcionario.instancia == null){
            Funcionario.instancia = new Funcionario(nome);
        }
    }

    public static Funcionario getInstancia(){
        return Funcionario.instancia;
    }

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
}