import java.util.Comparator;

public class ComparaPessoaNome implements Comparator<Pessoa>{

    @Override
    public int compareTo(Pessoa p1, Pessoa p2){
        return p1.getNome().compareTo(p2.getNome());
    }
}