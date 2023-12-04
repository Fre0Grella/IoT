import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Finestra implements ActionListener {

    JFrame frame;
    JButton bottone;
    SerialCommChannel serial = new SerialCommChannel(9600);

    public Finestra() {
        frame = new JFrame();

        bottone = new JButton("Maintanance Done!");

        bottone.addActionListener(this); // Aggiungiamo l'action listener al botton (this perchè implementiamo ActionListener in questa classe)

        bottone.setBounds(100, 150, 100, 50);

        frame.add(bottone);

        frame.setSize(300, 400);

        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        Finestra f = new Finestra();
    }

    // Questo è il metodo che verrà chiamato quando clicchiamo il bottone
    public void actionPerformed(ActionEvent e) {
        
    }

} 