package Level;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import sample.Constants;

/**
 * Created by katrin on 4/24/16.
 */
public class Level {

    @FXML
    public Label level1;
    public Label level2;
    public Canvas canvas;

    public GraphicsContext gc;
    public Image fon;

    @FXML
    public void initialize() {
        fon = new Image("/images/fon2.jpg");
        gc = canvas.getGraphicsContext2D();

        gc.drawImage(fon, 0, 0, Constants.MAP_WIDTH, Constants.MAP_HEIGHT);

        level1.addEventHandler(MouseEvent.MOUSE_MOVED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                level1.setTextFill(Color.TEAL);
            }
        });
        level1.addEventHandler(MouseEvent.MOUSE_EXITED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                level1.setTextFill(Color.BLACK);
            }
        });


        level2.addEventHandler(MouseEvent.MOUSE_MOVED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                level2.setTextFill(Color.TEAL);
            }
        });
        level2.addEventHandler(MouseEvent.MOUSE_EXITED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event)
            {
                level2.setTextFill(Color.BLACK);
            }
        });
    }
}