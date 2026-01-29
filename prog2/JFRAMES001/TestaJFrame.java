import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JDialog;
public class TestaJFrame{
    public static void main(String[] args){
        JFrame quadro = new JFrame("Minha Aplicacao");
        quadro.setVisible(true);
        quadro.setSize(300, 300);
        quadro.setLocationRelativeTo(null);
        quadro.setVisible(true);
        quadro.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Scanner sc = new Scanner(System.in);

        // String titulo = sc.nextLine();

        JButton botaoSomar = new JButton("Somar");
        JTextField campoNumero1 = new JTextField();
        quadro.add(botaoSomar);
        quadro.add(campoNumero1);

    }
}