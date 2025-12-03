public class Main{
    public static void main(String[] args){
        PessoaFisica pf = new PessoaFisica("Teste", "12345");
        pf.exibirNome();
        PessoaJuridica pj = new PessoaJuridica("Teste", "1235566");
        pj.exibirNome();
    }   
}