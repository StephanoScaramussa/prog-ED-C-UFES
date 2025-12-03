import java.util.ArrayList;
//java.lang.String ==> String
public class A{
    public static void main(String[] args){
        ArrayList<Integer> numeros = new ArrayList<>();

        numeros.add(new Integer(10));
        numeros.add(11); //autoempacotamento
        System.out.println(numeros.size());
        System.out.println(numeros.contains(11));
        System.out.println(numeros.remove(11));
    }
}