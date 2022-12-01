
/**
 * Write a description of class FileSize here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */

import java.io.File;
import java.util.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.lang.Math;

public class FileSize
{
    public static ArrayList<Entry> entries = new ArrayList<>();

    private static long getFolderSize(File folder, int iteration)
    {
        long length = 0;
        int first = iteration + 1;
        long sizet = 0;
        File[] files = folder.listFiles();
        int count = files.length;
        for (int i = 0; i < count; i++) {
            if (files[i].isFile()) {
                length += files[i].length();
            }
            else {
                sizet = getFolderSize(files[i], first);
                if (first <= 1)
                {                    
                    Entry temp = new Entry(files[i].getName(),sizet);
                    entries.add(temp);
                }
                length += sizet;
            }
        }
        return length;
    }

    public static void main(String[] args)
    {
        File file1 = new File("C:\\Users\\owner\\Desktop\\School Stuff\\Y4S1 Fall 2022\\3 - ECE 4318.01\\Report 5\\Proj5\\java 9th edition Code examples");
        System.out.println("Folder\t\t\tSize of folder in bytes");
        long size = getFolderSize(file1, 0);
        Collections.sort(entries);
        for (int i=0; i<entries.size(); i++)
        {
            System.out.println(entries.get(i));
        }
        System.out.println("Size of " + file1 + " is " + size + " B");
        System.out.println("Size of " + file1 + " is " + (double)size / 1024 + " KB");
        System.out.println("Size of " + file1 + " is " + (double)size / (1024 * 1024) + " MB");
    }
}
