package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;

/**
 * Created by katrin on 3/5/16.
 */
public class Hole extends DrawItems implements Serializable{
    private static Image image_of_hole;


    public Hole(int x, int y) {
        setX(x);
        setY(y);
        image_of_hole = new Image("images/hole.png");
    }

    //public boolean open(){ }
    //public boolean cat_close(){ }

    public void draw(GraphicsContext gc) {
        gc.drawImage(image_of_hole, getX() - 16, getY() - 16);
    }
}
