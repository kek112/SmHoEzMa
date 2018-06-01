using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SensorAPI.Controllers
{
    public class Stuff
    {
        public int GetRandomNumber(int minimum, int maximum)
        {
            Random random = new Random();
            return random.Next(minimum, maximum);
        }
    }
}