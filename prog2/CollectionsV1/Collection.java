import java.util.ArrayList;
import java.util.TreeSet;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Collections;

public class Collection{
    public static void main(String[] args){
        ArrayList<Integer> col1 = new ArrayList<>();
        HashSet<Integer> col2 = new HashSet<>(); //HashSet simula conjunto sem indice
        TreeSet<Integer> col3 = new TreeSet<>();

        //manipulando uma ArrayList ----------------------------------------------------------------
        col1.add(2);
        col1.add(2);
        col1.add(5);
        col1.add(2);
        col1.add(3);

        System.out.println(col1);

        Collections.sort.col2(); //ordena

        System.out.println(col1);

        while col1.contains(2){ //remove todas as ocorrencias de 2
            col1.remove(new Integer(2));
        }

        System.out.println(col1);

        //manipulando um HashSet ----------------------------------------------------------------
        col2.add(4);
        col2.add(4); //HashSet nao deixa inserir repeticao -> add : false
        col2.add(40);
        col2.add(41);
        col2.add(42);

        for(Integer numero : col2){ //for it (iterar em um hashset)
            System.out.println(numero);
        }

        Iterator<Integer> ite = col2.iterator(); //Objetos iterator implementam a interface Iterator

        while(ite.hasNext()){ //enquanto nao for o ultimo
            int temp = ite.next(); //apos um next, retorna o atual, e passa para o proximo elemento
            System.out.println(temp);
            if(temp == 2){
                ite.remove();
            }
        }

        col2.remove(2);// no ArrayList, usar um int revome o indice, instanciar um 2 remove os objetos 2

        ite = col2.iterator(); //apos usar um iterator e preciso recria-lo, mas ele ja possui tipo

        //manipulando um TreeSet ----------------------------------------------------------------
        col3.add(1);
        col3.add(1); //TreeSet nao deixa inserir repeticao -> add : false
        col3.add(14);
        col3.add(11);
        col3.add(13);
        col3.add(12);

        for(Integer numero : col3){
            System.out.println(numero); //imprime na ordem de insercao
        }
    }
}