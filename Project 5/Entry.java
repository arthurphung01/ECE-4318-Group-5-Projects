
/**
 * Write a description of class Entry here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Entry implements Comparable<Entry>
{
    // instance variables - replace the example below with your own
    private long size;
    private String name;

    /**
     * Constructor for objects of class Entry
     */
    public Entry(String n, long sz)
    {
        name = n;
        size = sz;
    }
    
    @Override
    public int compareTo(Entry e)
    {
        return (int) (this.size - e.getSize());
    }
    
    public long getSize()
    {
        return size;
    }
    
    @Override
    public String toString()
    {
        return name + "\t\t\t" + getSize();
    }
}
