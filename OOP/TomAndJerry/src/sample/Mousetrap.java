package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;

/**
 * Created by katrin on 4/24/16.
 */
public class Mousetrap extends DrawItems implements Serializable {
    public static Image image_mtr;

    public Mousetrap(int x, int y)
    {
        setX(x);
        setY(y);

        image_mtr = new Image("/images/mousetrap.png");
    }

    public void draw(GraphicsContext gc) {
        gc.drawImage(image_mtr, getX() - 16, getY() - 16);
    }
}
