package sample;

import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

/**
 * Created by katrin on 4/24/16.
 */
public class LittleChesse extends Cheese{

    private static Image image_of_cheese;

    public LittleChesse(int x, int y)
    {
        setX(x);
        setY(y);

        image_of_cheese = new Image("/images/cheese/cheese.png");
        IsEaten = false;
        score = 10;
    }
    public void draw(GraphicsContext gc)
    {
        if(IsEaten == false)
        {
            gc.drawImage(image_of_cheese, getX() - 16, getY() - 16);
        }
    }
}
