using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyDirectory
{
    class CmdLine
    {
        public static void MakeDir(string[] input_words)
        {
            for (int i = 1; i < input_words.Length; i++)
            {
                string path = Directory.GetCurrentDirectory() + "\\" + input_words[i];
            if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
            else
                {
                    Console.WriteLine($"\nDirectory or file '{input_words[i]}' already exist!");
                }
            }
        }
        public static void RemoveDir(string[] input_words)
        {
            for (int i = 1; i < input_words.Length; i++)
            {
                string path = Directory.GetCurrentDirectory() + "\\" + input_words[i];
                if (Directory.Exists(path))
                {
                    Directory.Delete(path);
                }
                else
                {
                    Console.WriteLine($"\nThe specified file or directory '{input_words[i]}' cannot be found.!");
                }
            }
        }
        public static void ChangeDir(string[] input_words)
        {
            string full_dir_name = "";
            if (input_words[0] == "C:" || input_words[0] == "D:" || input_words[0] == "F:" || input_words[0] == "G:")
            {
                Directory.SetCurrentDirectory(input_words[0] + "\\");
                return;
            }
            else if (input_words[1] == "..")
            {
                Directory.SetCurrentDirectory(input_words[1]);
                return;
            }
            else
            {
                for (int i = 1; i < input_words.Length; i++)
                {
                    full_dir_name += input_words[i] + " ";
                }
                if (Directory.Exists(full_dir_name))
                {
                    Directory.SetCurrentDirectory(full_dir_name);
                }
                else
                {
                    Console.WriteLine($"\nThe specified file or directory '{input_words[1]}' cannot be found!");
                }
            }
        }
        public static void PrintCurrentDir(string[] input_words)
        {
            if (CheckFullPath(input_words))
            {
                string full_path = input_words[1];
                if (Directory.Exists(full_path))
                    ShowFilesDirectories(full_path);
                else
                    Console.WriteLine($"\nThe specified file or directory '{full_path}' cannot be found!");
            }
            else
            {
                ShowFilesDirectories(Directory.GetCurrentDirectory());
            }
        }
        public static void CreateTextFile(string[] input_words)
        {
            if (input_words[1].Contains(".txt"))
            {
                string text = "";
                for (int i = 2; i < input_words.Length; i++)
                {
                    text += input_words[i] + " ";
                }
                File.WriteAllText($"{input_words[1]}", $"{text}");
            }
            else {
                Console.WriteLine("Incorrect file name!");
            }
        }
        public static void PrintTextFile(string[] input_words)
        {
            if (CheckFullPath(input_words))
            {
                string full_path = input_words[1];
                ReadFile(full_path);
            }
            else
            {
                string file_name = input_words[1], path = Directory.GetCurrentDirectory() + "\\" + file_name;
                ReadFile(path);
            }
        }
        public static void CopyTextFile(string[] input_words)
        {
            if (CheckFullPath(input_words))
            {
                string full_path_file = input_words[1], full_path_copy_file = input_words[2];
                if (File.Exists(full_path_file))
                {
                    File.Copy(full_path_file, full_path_copy_file);
                }
                else
                {
                    Console.WriteLine($"\nThe specified file or directory '{full_path_file}' cannot be found!");
                }
            }
            else
            {
                string file_name = input_words[1], copy_file_name = input_words[2],
                       path_file = Directory.GetCurrentDirectory() + "\\" + file_name,
                       path_copy_file = Directory.GetCurrentDirectory() + "\\" + copy_file_name;
                if (File.Exists(path_file))
                {
                    File.Copy(file_name, copy_file_name);
                }
                else
                {
                    Console.WriteLine($"\nThe specified file or directory '{path_file}' cannot be found!");
                }
            }
        }
        public static void RemoveTextFile(string[]input_words)
        {
            if (CheckFullPath(input_words))
            {
                string full_path = input_words[1];
                DeleteFile(full_path);
            }
            else
            {
                string full_path = Directory.GetCurrentDirectory() + "\\" + input_words[1];
                DeleteFile(full_path);
            } 
        }
        public static void AppendTextFile(string[] input_words)
        {
            string content = " ";
            if (input_words.Length >= 3)
            {
                for (int i = 2; i < input_words.Length; i++)
                {
                    content += input_words[i] + " ";
                }
            }
            else
            {
                Console.WriteLine("\nYou must enter some content!");
            }
            if (CheckFullPath(input_words))
            {
                string full_path = input_words[1];
                
                if (File.Exists(full_path))
                    File.AppendAllText(full_path, content);
                else
                    Console.WriteLine($"\nThe specified file or directory '{full_path}' cannot be found!");
            }
            else
            {
                if (File.Exists(Directory.GetCurrentDirectory() + "\\" + input_words[1]))
                {
                    if (input_words.Length >= 3)
                    {
                        File.AppendAllText(Directory.GetCurrentDirectory() + "\\" + input_words[1], input_words[2]);
                    }
                    else
                    {
                        Console.WriteLine("\nYou must enter some content!");
                    }
                }
                else
                {
                    Console.WriteLine($"\nThe specified file or directory '{input_words[1]}' cannot be found!");
                }
            }
        }
        static bool CheckFullPath(string[] input_words)
        {
            string[] disc = { "C:\\", "D:\\", "E:\\", "F:\\", "I:\\", "G:\\" };
            bool is_full_path = false;
            if (input_words.Length > 1)
            {
                for (int i = 0; i < disc.Length; i++)
                {
                    if (input_words[1].Contains(disc[i]))
                    {
                        is_full_path = true;
                        return true;
                    }
                }
            }
            return false;
        }
        static void ShowFilesDirectories(string path)
        {
            uint dir_count = 0, file_count = 0;
            long files_size = 0;
            Console.WriteLine($"\nThe content of the folder {path}\n");
            foreach (var dir in Directory.GetDirectories(path))
            {
                Console.WriteLine($"{Directory.GetCreationTime(dir)}\t<DIR>\t\t{Path.GetFileName(dir),-10}");
                ++dir_count;
            }
            DirectoryInfo di = new DirectoryInfo(path);
            FileInfo[] fileArr = di.GetFiles();
            DriveInfo drive = new DriveInfo(path);
            foreach (var file in fileArr)
            {
                Console.WriteLine($"{file.CreationTime}\t{file.Length} \t\t{file.Name}");
                ++file_count;
                files_size += file.Length;
            }

            Console.WriteLine($"\tFiles: { file_count}\t\t{files_size} bytes\n\tDirectory : {dir_count}\t\t{drive.AvailableFreeSpace} bytes free");

        }
        static void ReadFile(string path)
        {
            if (File.Exists(path))
            {
                Console.WriteLine($"\n{File.ReadAllText(path)}");
            }
            else
            {
                Console.WriteLine($"\nThe specified file or directory '{path}' cannot be found!");
            }
        }
        static void DeleteFile(string path)
        {
            if (File.Exists(path))
            {
                File.Delete(path);
            }
            else
            {
                Console.WriteLine($"\nThe specified file or directory '{path}' cannot be found!");
            }
        }
    }
}
