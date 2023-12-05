package it.unibo.samplejavafx;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 * Sample JavaFX application.
 */
public final class JavaFXApp extends Application {

    SerialCommChannel serial;

    @Override
    public void start(final Stage primaryStage) throws Exception {
        serial = new SerialCommChannel("COM7", 9600);
        Text text = new Text();      
        Text text2 = new Text();     
        int count = 0; 
        float temperature = 0;
        text.setText("total number of washes done: " + count); 
        text2.setText("Temperature in washing: " + temperature); 
        text.setX(325); 
        text.setY(50); 
        text2.setX(325); 
        text2.setY(100); 
        //Creating a Button
        Button button = new Button();
        //Setting text to the button
        button.setText("MAINTENANCE REQUIRED");
        //Setting the location of the button
        button.setTranslateX(325);
        button.setTranslateY(300);
        //Setting the stage
        Group root = new Group(button, text, text2);
        Scene scene = new Scene(root, 800, 800, Color.WHITE);
        primaryStage.setTitle("Button Example");
        primaryStage.setScene(scene);
        primaryStage.show();
        
        var thread = new Thread(() -> {
            while (true) {
                try {
                    var msg = serial.receiveMsg();

                    if (true) {

                    }
                    Thread.sleep(250);
                    break;
                } catch(InterruptedException e) {
                    System.err.println(e);
                } 
            }
        });
        thread.start();
        
    }

    /**
     * Program's entry point.
     * @param args
     */
    public static void run(final String... args) {
        launch(args);
    }

    // Defining the main methods directly within JavaFXApp may be problematic:
    // public static void main(final String[] args) {
    //        run();
    // }

    /**
     * Entry point's class.
     */
    public static final class Main {
        private Main() {
            // the constructor will never be called directly.
        }

        /**
         * Program's entry point.
         * @param args
         */
        public static void main(final String... args) {
            Application.launch(JavaFXApp.class, args);
            /* 
            The following line raises: Error: class it.unibo.samplejavafx.JavaFXApp$Main 
            is not a subclass of javafx.application.Application
            Because if you do not provide the Application subclass to launch() it will consider the enclosing class)
            */
            // JavaFXApp.launch(args);
            // Whereas the following would do just fine:
            // JavaFXApp.run(args)
        }
    }
}
