using Interfaces;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFileStream
{
    class FileWorker
    {
        public static void SaveEmployee(List<Employee> em_list, string fname)
        {
            using (BinaryWriter bw = new BinaryWriter(new FileStream(fname, FileMode.Create)))
            {
                int[] res;
                //byte[] tmp;
                int list_count = em_list.Count;                              
                bw.Write(list_count);                                               // write size of list
                for (int i = 0; i < em_list.Count; i++)
                {
                    bw.Write(em_list[i].Name);                                      // write each field of object to the file
                    bw.Write(em_list[i].SurName);
                    bw.Write(em_list[i].Position);
                    bw.Write(em_list[i].Salary);
                    bw.Write(em_list[i].ContractNumber);

                    res = em_list[i].GetPoints();                                  // get points (int array)
                    bw.Write(res.Length);                                           // write size of int array

                    /* for (int j = 0; j < res.Length; j++)                           // write Points (int[]) to the file
                     {
                         tmp = BitConverter.GetBytes(res[j]);                         // convert int[] to byte[]
                         bw.Write(tmp);                                                // write byte[] to the file
                     }*/

                    for (int j = 0; j < res.Length; j++)                                    // write Points (int[]) to the file without converting to byte[]
                    {
                        bw.Write(res[j]);
                    }
                }
            }
        }

        public static List<Employee> LoadEmployee(string fname)
        {

           List<Employee> result = new();
            using (BinaryReader br = new BinaryReader(new FileStream(fname, FileMode.Open)))
            {
                int[] res;
               // byte[] tmp;
                int list_size = br.ReadInt32();                           // read size of list
                
                for (int i = 0; i < list_size; i++)
                {
                    Employee em = new Employee();                       // read each field of object from the file
                    em.Name = br.ReadString();
                    em.SurName = br.ReadString();
                    em.Position = br.ReadString();
                    em.Salary = br.ReadUInt16();
                    em.ContractNumber = br.ReadString();

                    int arr_size = br.ReadInt32();                     // read size of Points (int[])
                    res = new int[arr_size];                             // create new int[]
                    //tmp = new byte[sizeof(int)];                        // create new byte[]

                    /* for (int j = 0; j < res.Length; j++)
                     {
                         br.Read(tmp);
                         res[j] = BitConverter.ToInt32(tmp);                // read byte[] from the file and convert to int[]
                     }*/
                    for (int j = 0; j < res.Length; j++)
                    {
                        res[i] = br.ReadInt32();                           // read int[] from the file
                    }

                    em.AddPoint(res);                                      // Add Points to object
                    result.Add(em);                                        // Add full object to the List<Employee>
                }
                return result;                                             // return List<>
            }
        }
    }
}
