public class Retangulo{
    int base;
    int altura;
    public Retangulo(){
    }
    public Retangulo(int base, int altura){
        this.base = base;
        this.altura = altura;
    }
    public void setBase(int base){
        this.base = base;
    }
    public int getBase(){
        return base;
    }
    public void setAltura(int altura){
        this.altura = altura;
    }
    public int getAltura(){
        return altura;
    }
    public int calculaArea(){
        return base*altura;
    }
}