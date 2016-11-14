package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

import java.io.Serializable;

/**
 * Created by katrin on 3/21/16.
 */
public class BlackOil extends DrawItems implements Serializable{
    public static Image image_oil;
    public boolean IVisible;

    public BlackOil(int x, int y){
        setX(x);
        setY(y);

        IVisible = true;
        image_oil = new Image("/images/oil.png");
    }

    public void draw(GraphicsContext gc)
    {
        if (IVisible)
        {
            gc.drawImage(image_oil, getX() - 24, getY() - 16);
        }
    }
}
