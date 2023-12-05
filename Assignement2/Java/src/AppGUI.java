import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.Thread;

public class AppGUI implements ActionListener {

    JFrame frame;
    JButton bottone;
    SerialCommChannel serial;

    public AppGUI() {
        serial = new SerialCommChannel(null, 9600);
        frame = new JFrame();

        bottone = new JButton("Maintanance Done!");

        bottone.addActionListener(this); // Aggiungiamo l'action listener al botton (this perchè implementiamo ActionListener in questa classe)

        bottone.setBounds(100, 150, 100, 50);

        frame.add(bottone);

        frame.setSize(300, 400);

        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);


        var thread = new Thread(() -> {
            while (true) {
                try {
                    var msg = serial.receiveMsg();

                    if (true) {



                    }

                    Thread.sleep(250);
                }
            }
        });
        thread.start();
    }

    public static void main(String[] args) {
        AppGUI f = new AppGUI();
    }

    // Questo è il metodo che verrà chiamato quando clicchiamo il bottone
    public void actionPerformed(ActionEvent e) {
        
    }

} 
