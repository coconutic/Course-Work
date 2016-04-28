package CatStrategies;

import sample.CatTom;
import sample.DrawItems;
import sample.Position;

import java.util.ArrayList;
import java.util.Calendar;

/**
 * Created by katrin on 4/6/16.
 */
public class CalmStrategy implements Strategy {

    private boolean Move;
    private boolean IsGo;

    private ArrayList<Position> pos;
    private ArrayList<Position> wayback;

    private int way;
    private int lastpos;

    public CalmStrategy(){
        Move = true;
        IsGo = false;
        way = 0;
        lastpos = 0;
        pos = new ArrayList<Position>();
        wayback = new ArrayList<Position>();

        pos.add(new Position(200, 620));
        pos.add(new Position(1100, 622));
        pos.add(new Position(1102, 433));
        pos.add(new Position(332, 430));
        pos.add(new Position(330, 152));
        pos.add(new Position(212, 150));
     //   pos.add(new Position(330, 155));
    }

    public int getPos(int curx, int cury){
        for (int i = 0; i < pos.size() - 1; i++){
            int x1 = pos.get(i).getX();
            int x2 = pos.get(i + 1).getX();
            int y1 = pos.get(i).getY();
            int y2 = pos.get(i + 1).getY();

            if (y1 > y2)
            {
                int temp = y1;
                y1 = y2;
                y2 = temp;
            }

            if (x1 > x2)
            {
                int temp = x1;
                x1 = x2;
                x2 = temp;
            }
            /*
            System.out.println(String.format("%d %d %d", x1, curx, x2));
             System.out.println(String.format("%d %d %d", y1, cury, y2));
             */
            if ((x1 <= curx && curx <= x2) && (y1 <= cury && cury <= y2))
            {
                return i + 1;
            }
        }
        return -1;
    }

    public void create_way(sample.CatTom cat, ArrayList<sample.DrawItems> items)
    {
        int curX = cat.getX();
        int curY = cat.getY();


    }

    public void go_path(sample.CatTom cat)
    {
        int curX = cat.getX();
        int curY = cat.getY();

        for (int i = 0; i < wayback.size(); i++)
        {
            int posX = wayback.get(i).getX();
            int posY = wayback.get(i).getY();

            if (curX == posX && curY == posY){
                //cat.setX();
            }
        }
    }
    public void go_back(sample.CatTom cat, ArrayList<sample.DrawItems> items)
    {
        if (wayback.size() == 0){
            create_way(cat, items);
        }
        go_path(cat);
    }

    @Override
    public void Action(sample.CatTom cat, ArrayList<sample.DrawItems> items) {
        int goalx;
        int goaly;
        IsGo = false;
        lastpos = cat.getLastpos();

        int x = cat.getX();
        int y = cat.getY();

        int poss = lastpos + 1;
        int g_index = 0;

        int dx[] ={0, 4, 4, 4, 0, -4, -4, -4};
        int dy[] ={-4, -4, 0, 4, 4, 4, 0, -4};

        double minimal_distance = 10000;

        if (!Move)
        {
            goalx = pos.get(lastpos).getX();
            goaly = pos.get(lastpos).getY();
        } else
        {
            goalx = pos.get(poss).getX();
            goaly = pos.get(poss).getY();
        }
            for (int i = 0; i < 8; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                double distance = Math.sqrt((double)((goalx - new_x)* (goalx - new_x) +
                           (goaly - new_y) * (goaly - new_y)));

                if (distance < minimal_distance) {
                    minimal_distance = distance;
                    g_index = i;
                }
            }
        int newX = x + dx[g_index];
        int newY = y + dy[g_index];

    /*  System.out.println(String.format("%d %d %d", pos.get(lastpos).getX(), newX, pos.get(poss).getX()));
        System.out.println(String.format("%d %d %d", pos.get(lastpos).getY(), newY, pos.get(poss).getY()));
        System.out.println(String.format("%d %d", goalx, goaly));
        System.out.println(Move);
*/
        int x1 = pos.get(lastpos).getX();
        int y1 = pos.get(lastpos).getY();
        int x2 = pos.get(poss).getX();
        int y2 = pos.get(poss).getY();
        if (x1 > x2) {
            int t = x1;
            x1 = x2;
            x2 = t;
        }
        if (y1 > y2) {
            int t = y1;
            y1 = y2;
            y2 = t;
        }


        if ((x1 <= newX && newX <= x2) &&
                y1 <= newY && newY <= y2 &&
                (newX != goalx || newY != goaly)) {
            IsGo = true;
            cat.setX(newX);
            cat.setY(newY);
        } else {
            if (!Move) {
                lastpos--;
            } else {
                lastpos++;
            }

            if (lastpos <= 0) {
                Move = true;
                lastpos++;
            }

            if (lastpos == pos.size() - 1) {
                Move = false;
                lastpos--;
            }
        }
        cat.setLastpos(lastpos);
        if (!IsGo)
        {
            go_back(cat, items);
        }
    }
}
