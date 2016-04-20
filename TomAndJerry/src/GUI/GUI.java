package GUI;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import sample.Constants;

/**
 * Created by katrin on 4/7/16.
 */
public class GUI {

    @FXML
    public Label play;

    @FXML
    public Label level;

    @FXML
    Canvas canvas;

    public GraphicsContext gc;
    public Image fon;

    @FXML
    public void initialize() {
        fon = new Image("/fon/f.jpg");
        gc = canvas.getGraphicsContext2D();

        gc.drawImage(fon, 0, 0, Constants.MAP_WIDTH, Constants.MAP_HEIGHT);

        play.setTextFill(Color.DODGERBLUE);
        play.addEventHandler(MouseEvent.MOUSE_MOVED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                play.setTextFill(Color.ORANGERED);
            }
        });
        play.addEventHandler(MouseEvent.MOUSE_EXITED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                play.setTextFill(Color.DODGERBLUE);
            }
        });


        level.setTextFill(Color.DODGERBLUE);
        level.addEventHandler(MouseEvent.MOUSE_MOVED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                level.setTextFill(Color.ORANGERED);
            }
        });
        level.addEventHandler(MouseEvent.MOUSE_EXITED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                level.setTextFill(Color.DODGERBLUE);
            }
        });
    }
}
