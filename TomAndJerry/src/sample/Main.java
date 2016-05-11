package sample;

import GUI.GUI;
import Level.Level;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.KeyCombination;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;


public class Main extends Application {

    public static boolean level1;

    public void go_to_level(FXMLLoader ld, Scene scene) throws IOException{
        Level l = (Level)ld.getController();

        l.level1.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                System.out.println("in handler");
                try{
                    level1 = true;

                    Parent root3 =  FXMLLoader.load(getClass().getResource("/sample/sample.fxml"));
                    scene.setRoot(root3);
                } catch (Exception e){
                    System.out.println(e);
                }
            }
        });

        l.level2.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                try{
                    level1 = false;

                    Parent root3 =  FXMLLoader.load(getClass().getResource("/sample/sample.fxml"));
                    scene.setRoot(root3);
                } catch (Exception e){
                    System.out.println(e);
                }
            }
        });
    }


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
                    level1 = true;

                    Parent root1 =  FXMLLoader.load(getClass().getResource("sample.fxml"));
                    scene.setRoot(root1);
                } catch (Exception e){
                    System.out.println(e);
                }
            }
        });

        gui.level.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                try{
                    //Parent root2 = FXMLLoader.load(getClass().getResource("/Level/level.fxml"));
                    //scene.setRoot(root2);

                    fxmlLoader.setRoot(null);
                    fxmlLoader.setController(null);
                    fxmlLoader.setLocation(getClass().getResource("/Level/level.fxml"));
                    Parent s = fxmlLoader.load();
                    scene.setRoot(s);
                    go_to_level(fxmlLoader, scene);
                } catch (Exception e){
                    System.out.println(e);
                }
            }
        });

   }


    public static void main(String[] args) {
        launch(args);
    }
}

