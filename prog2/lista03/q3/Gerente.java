public class Gerente extends Funcionario{
    public Gerente(String nome, double valor_hora, double horas_trab){
        super(nome, valor_hora, horas_trab);
    }
    @Override
    public double calcularSalario(){
        return (getHoras_trab() * getValor_hora()) + 0.2 * (getHoras_trab() * getValor_hora());
    }
}