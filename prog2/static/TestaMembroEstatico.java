public class TestaMembroEstatico{
    public static void main(String[] args){
        Funcionario.criaInstancia("Ciclano");

        public Funcionario f1 = Funcionario.getInstancia();

        System.out.println(f1.getNome());
    }
}