using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'lilysHomework' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

   static int CountSwaps(List<int> arr, List<int> sorted)
    {
        int n = arr.Count;
        Dictionary<int, int> pos = new Dictionary<int, int>();

        for (int i = 0; i < n; i++)
        {
            pos[sorted[i]] = i;
        }

        bool[] visited = new bool[n];
        int swaps = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] || pos[arr[i]] == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j])
            {
                visited[j] = true;
                j = pos[arr[j]];
                cycleSize++;
            }

            if (cycleSize > 1)
                swaps += (cycleSize - 1);
        }

        return swaps;
    }


    public static int lilysHomework(List<int> arr)
    {
        List<int> asc = new List<int>(arr);
        List<int> desc = new List<int>(arr);

        asc.Sort();
        desc.Sort((a, b) => b.CompareTo(a));

        int ascSwaps = CountSwaps(arr, asc);
        int descSwaps = CountSwaps(arr, desc);

        return Math.Min(ascSwaps, descSwaps);
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

        int result = Result.lilysHomework(arr);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
