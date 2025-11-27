public class Carro{
    String marca;
    String modelo;
    int ano;
    Roda[] rodas;
    public Carro(String marca, String modelo, int ano){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        rodas = new Roda[4];
        // rodas[0] = new Roda();
        // rodas[1] = new Roda();
        // rodas[2] = new Roda();
        // rodas[3] = new Roda();
        for(int i = 0; i < 4; i++){
            rodas[i] = new Roda();
        }
    }
}