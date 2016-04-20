package sample;

import GUI.GUI;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.KeyCombination;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;


public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("/GUI/gui.fxml"));
        Parent root = fxmlLoader.load();
        primaryStage.setTitle("Tom and Jerry");
        Scene scene = new Scene(root);
        primaryStage.setScene(scene);
        primaryStage.setFullScreen(true);
        primaryStage.setFullScreenExitKeyCombination(KeyCombination.NO_MATCH);
        primaryStage.show();

        GUI gui = (GUI)fxmlLoader.getController();

        gui.play.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                try {

                    Parent root1 =  FXMLLoader.load(getClass().getResource("sample.fxml"));
                    primaryStage.setTitle("Tom and Jerry");
                    scene.setRoot(root1);
                    primaryStage.setScene(scene);
                    primaryStage.setFullScreen(true);
                    primaryStage.setFullScreenExitKeyCombination(KeyCombination.NO_MATCH);
                    primaryStage.show();
                } catch (Exception e){

                }
            }
        });
    }

    public static void main(String[] args) {
        launch(args);
    }
}



