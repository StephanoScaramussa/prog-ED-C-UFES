public class Main{
    public static void main(String[] args){
        Funcionario f1 = new Gerente("Joao", 54.6, 50);
        System.out.println(f1.calcularSalario());
    }
}