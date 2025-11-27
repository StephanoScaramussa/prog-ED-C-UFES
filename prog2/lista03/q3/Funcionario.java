public class Funcionario{
    public String nome;
    public double valor_hora;
    public double horas_trab;
    public Funcionario(String nome, double valor_hora, double horas_trab){
        this.nome = nome;
        this.valor_hora = valor_hora;
        this.horas_trab = horas_trab;
    }
    public double calcularSalario(){
        return valor_hora*horas_trab;
    }
    public double getValor_hora(){
        return valor_hora;
    }
    public double getHoras_trab(){
        return horas_trab;
    }
}