using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dir___files
{
    class Program
    {
// 1. Створити папку А, з двома підпапками В та С.В кожній папці - по одному текстовому файлу. ...Вилучити папку А(DirectoryINfo).
// 2. Вивести всі файли з  деякої  папки, та їх сумарний розмір  та кількість.
        static void Main(string[] args)
        {
            string[] DirArr = { "../../../A", "../../../B", "../../../C" };
            string Dir = ".. / .. / .. /";
            for (int i = 0; i < DirArr.Length; i++)
            {
                if (!Directory.Exists(DirArr[i]))
                {
                    Directory.CreateDirectory(DirArr[i]);
                }
            }
            for (int i = 0; i < DirArr.Length; i++)
            {
                if (Directory.GetCurrentDirectory() != Dir)
                {
                    Directory.SetCurrentDirectory($"../");
                }
                Directory.SetCurrentDirectory(DirArr[i]);
                File.WriteAllText($"MyFile{i}.txt", $"Hello file {i}");

            }

            /*Directory.SetCurrentDirectory(DirArr[0]);
            File.WriteAllText($"MyFile{0}.txt", $"Hello file {0}");
            Directory.SetCurrentDirectory($"../");
            Directory.SetCurrentDirectory(DirArr[1]);
            File.WriteAllText($"MyFile{1}.txt", $"Hello file {1}");
            Directory.SetCurrentDirectory($"../");
            Directory.SetCurrentDirectory(DirArr[2]);
            File.WriteAllText($"MyFile{2}.txt", $"Hello file {2}");*/



            Console.ReadKey();
            DirectoryInfo di = new DirectoryInfo(DirArr[0]);
            if (!di.Exists)
            {
                di.Delete();

            }



        }
    }
}
