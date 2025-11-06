public class Main{
    public static void main(String[] args){
        Retangulo r1 = new Retangulo(5,3);
        Retangulo r2 = new Retangulo();
        r2.setBase(4);
        r2.setAltura(4);
        System.out.println("Area r1: " + r1.calculaArea());
        System.out.println("Area r2: " + r2.calculaArea());
    }
}