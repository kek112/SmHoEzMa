using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SensorAPI.Models
{
    public class NodeMCU
    {
        public int Value { get; set; }
        public String IP { get; set; }
        public String SensorName { get; set; }
        public int ID { get; set; }
    }
   
}