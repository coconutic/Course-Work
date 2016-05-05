package CatStrategies;

import javafx.geometry.Pos;
import javafx.util.Pair;
import sample.CatTom;
import sample.DrawItems;
import sample.Position;

import javax.jws.Oneway;
import java.util.*;

/**
 * Created by katrin on 4/6/16.
 */
public class CalmStrategy implements Strategy {
    private static int dx[] = {-4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    private static int dy[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4};

/*
    private static int dx[] = {-4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1,
                               -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    private static int dy[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1,
                                2, 3, 4, -4, -3, -2, -1, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4};
*/
    private boolean Move;
    private boolean IsGo;

  //  private ArrayList<Position> pos;
    private ArrayList<Position> wayback;

    private int way;
    private int lastpos;

    public CalmStrategy(CatTom cat){
        Move = true;
        IsGo = false;
        way = 0;
        lastpos = 0;
        cat.pos = new ArrayList<Position>();
        wayback = new ArrayList<Position>();
/*
        cat.pos.add(new Position(1230, 50));
        cat.pos.add(new Position(1230, 600));
        cat.pos.add(new Position(965, 600));
        cat.pos.add(new Position(965, 125));
        cat.pos.add(new Position(755,125));
        cat.pos.add(new Position(755, 580));
        cat.pos.add(new Position(500, 580));
        cat.pos.add(new Position(500, 180));
        cat.pos.add(new Position(250,180));
        cat.pos.add(new Position(250, 520));*/

        cat.pos.add(new Position(200, 620));
        cat.pos.add(new Position(1100, 620));
        cat.pos.add(new Position(1100, 430));
        cat.pos.add(new Position(330, 430));
        cat.pos.add(new Position(330, 150));
        cat.pos.add(new Position(210, 150));
     //   pos.add(new Position(330, 155));
    }

    /*public int getPos(int curx, int cury){
        for (int i = 0; i < cat.pos.size() - 1; i++){
            int x1 = pos.get(i).getX();
            int x2 = pos.get(i + 1).getX();
            int y1 = pos.get(i).getY(); int y2 = pos.get(i + 1).getY();

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

            if ((x1 <= curx && curx <= x2) && (y1 <= cury && cury <= y2))
            {
                return i + 1;
            }
        }
        return -1;
    }
*/
    private double getDistToTheWay(Position pos1, Position pos2, Position cur_pos) {
        double A = pos1.getY() - pos2.getY();
        double B = pos2.getX() - pos1.getX();
        double C = pos1.getX() * pos2.getY() - pos2.getX() * pos1.getY();

        double d = Math.abs(A * cur_pos.getX() + B * cur_pos.getY() + C) / Math.sqrt(A * A + B * B);
        return d;
    }

    private boolean isOnWay(Position cur_pos, sample.CatTom cat) {
        boolean f = false;

        for (int i = 0; i < cat.pos.size() - 1; i++) {
            int x1 = Math.min(cat.pos.get(i).getX(), cat.pos.get(i + 1).getX());
            int x2 = Math.max(cat.pos.get(i).getX(), cat.pos.get(i + 1).getX());
            int y1 = Math.min(cat.pos.get(i).getY(), cat.pos.get(i + 1).getY());
            int y2 = Math.max(cat.pos.get(i).getY(), cat.pos.get(i + 1).getY());

            if (getDistToTheWay(cat.pos.get(i), cat.pos.get(i + 1), cur_pos) <= 3 &&
                    x1 <= cur_pos.getX() && cur_pos.getX() <= x2 &&
                     y1 <= cur_pos.getY() && cur_pos.getY() <= y2) {
                cat.setLastpos(i);
                if (cat.getX() == cat.pos.get(i + 1).getX() &&
                        cat.getY() == cat.pos.get(i + 1).getY()) {
                    if (Move) {
                        cat.setLastpos(i + 1);              // CHECK IF POSS ENDS
                    }
                }
                f = true;
                break;
            }
        }
        if (!f) {
            cat.setLastpos(-100);
        }
        return f;
    }


    private void create_way(sample.CatTom cat, ArrayList<sample.DrawItems> items)
    {
        Queue<Pair<Position, Position> > q =
                new LinkedList<Pair<Position, Position> >();
        Map<Position, Position> history = new HashMap<Position, Position> ();
        q.add(new Pair<Position, Position>(new Position(cat.getX(), cat.getY()),
                                            new Position(-1, -1)));
        history.put(new Position(cat.getX(), cat.getY()), new Position(-1, -1));

        while (!q.isEmpty()) {
            Position cur = q.peek().getKey();
            Position from = q.peek().getValue();

            if (isOnWay(cur, cat)) {
                break;
            }
            q.poll();

            for (int i = 0; i < dx.length; i++) {
                int newx = cur.getX() + dx[i];
                int newy = cur.getY() + dy[i];

                if (!history.containsKey(new Position(newx, newy)) &&
                        cat.isFree(newx, newy, items)) {
                    q.add(new Pair<Position, Position>(new Position(newx, newy), cur));
                    history.put(new Position(newx, newy), cur);
                }
            }
        }

        Position cur = q.peek().getKey();
        q.clear();

        while (cur.getY() != -1) {
    //        System.out.println(String.format("x: %d y: %d", cur.getX(), cur.getY()));
            wayback.add(cur);
            cur = history.get(cur);
        }
  //  System.out.println("************************");
        for (int i = 0; i < wayback.size() / 2; i++) {
            Position temp = wayback.get(i);
            wayback.set(i, wayback.get(wayback.size() - i - 1));
            wayback.set(wayback.size() - i - 1, temp);
        }
    }

    public void go_path(sample.CatTom cat, ArrayList<sample.DrawItems> items)
    {
        int curX = cat.getX();
        int curY = cat.getY();
        int futureIndex = -1;

        for (int i = 0; i < wayback.size() - 1; i++)
        {
            int posX = wayback.get(i).getX();
            int posY = wayback.get(i).getY();
            if (curX == posX && curY == posY){
                futureIndex = i + 1;
                break;
            }
        }

        if (futureIndex == -1)
        {
            wayback.clear();
            create_way(cat, items);
            go_path(cat, items);
        } else {
            cat.setX(wayback.get(futureIndex).getX());
            cat.setY(wayback.get(futureIndex).getY());

            if (futureIndex ==  wayback.size() - 1) {
                System.out.println("in if");
                wayback.clear();
            }
        }
    }

    public void go_back(sample.CatTom cat, ArrayList<sample.DrawItems> items)
    {
        if (wayback.size() == 0){
            create_way(cat, items);
        }
        go_path(cat, items);
    }

    @Override
    public void Action(sample.CatTom cat, ArrayList<sample.DrawItems> items) {
        int goalx;
        int goaly;

        int x = cat.getX();
        int y = cat.getY();

        if (!isOnWay(new Position(x, y), cat)) {
            go_back(cat, items);
            System.out.println("not in way");
            return;
        } else {
        }
        lastpos = cat.getLastpos();
        int poss = lastpos + 1;

        if (!Move) {
            goalx = cat.pos.get(lastpos).getX();
            goaly = cat.pos.get(lastpos).getY();
        } else {
            goalx = cat.pos.get(poss).getX();
            goaly = cat.pos.get(poss).getY();
        }
/*
        int subx = goalx - x;
        int suby = goaly - y;

        System.out.println(String.format("Last Pos = %d", lastpos));
        System.out.println(String.format("Poss = %d", poss));
*/
        int index = 0;
        double minDist1 = 10000;
        double minDist2 = 10000;

 //       System.out.println("DEBUG HERE==========================================");
   //     System.out.println(String.format("I am here x = %d y = %d", x, y));
     //   System.out.println(String.format("goalx = %d goalY = %d", goalx, goaly));
        for (int i = 0; i < dx.length; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
/*
            if (!cat.isFree(newX, newY, items)) {
                continue;
            }
*/
            double dist1 = cat.dist(newX, newY, goalx, goaly);
            double dist2 = getDistToTheWay(cat.pos.get(lastpos), cat.pos.get(poss), new Position(newX, newY));

            if (newX == 1100 && newY == 620) {
               // System.out.println(String.format("dist to point = %f", dist1));
                //System.out.println(String.format("dist to line = %f", dist2));
            }

            if (dist1 <= minDist1) {
                if (dist2 <= 4) {
                    index = i;
                    minDist1 = dist1;
                }
            }

            //System.out.println(String.format("After index = %d, newx = %d, newy = %d", i, newX, newY));
            //System.out.println(String.format("Dist to point = %f, index = %d", minDist1, index));
        }

        //System.out.println("NODEBUG HERE==========================================");
       // System.out.println(minDist1);

//        System.out.println(dx[index]);
//        System.out.println(dy[index]);
        cat.setX(x + dx[index]);
        cat.setY(y + dy[index]);
/*
        int subNewx = goalx - cat.getX();
        int subNewy = goaly - cat.getY();
*/
       /* System.out.println(subNewx);
        System.out.println(subNewy);
        System.out.println("============================");
        System.out.println(Move);*/
/*
        if (subx * subNewx < 0 || suby * subNewy < 0 ||
                (subx * subNewx == 0 && suby * subNewy == 0)) {
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
        */

        if ((cat.getX() == cat.pos.get(cat.pos.size() - 1).getX() &&
                cat.getY() == cat.pos.get(cat.pos.size() - 1).getY()) ||
                (cat.getX() == cat.pos.get(0).getX() && cat.getY() == cat.pos.get(0).getY())) {
            Move = Move ^ true;
        }
        cat.setLastpos(lastpos);
    }
}
