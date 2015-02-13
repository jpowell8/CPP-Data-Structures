#include "Mimic.h"
#include "Pair.h"
#include <time.h>
//#include <srand>


//srand(time(0));

Mimic::Mimic(void)
{
} 


Mimic::~Mimic(void)
{
}


int Mimic::Duplicate(string prefix)
{
	Pair pair("","");
	//cout << "entered Duplicate Function" << endl;
	int jay=0;
for(int j=0; j<Prefix.size(); j++)
	{
		//pair = Prefix[j];/////////Will possibly cause seg fault
		if((Prefix[j].Key) == prefix)
		{
	//		cout << "returning j"  << endl;
		return j;
		}
		jay = j+1;
	}
//cout << "returning JAy in Duplicate" << endl;
return jay;
}



		//Part 1--------------------------------------------------------------
		/**
		 * createMap
		 *
		 * Creates a prefix-suffix map based on the input text.
		 *
		 * Go through the input text and examine each group of 3 words. Refer
		 * to the first two words as the "prefix" and the third word as the
		 * "suffix". Create a map that associates each prefix with each suffix.
		 *  If you encounter a prefix that has been read already, add the new
		 *  suffix to the list of suffixes already associated with that prefix;
		 *  in this manner, each prefix can be associated with multiple
		 *  suffixes and even multiple copies of the same suffix. Note that
		 *  the input texts will only contain words separated by spaces.  Also
		 *  note that the last two word prefix in the text should be associated
		 *  with the suffix "THE_END".
		 *
		 * @param input
		 * 		the sample text to be mimicked
		 */
		void Mimic::createMap(string input)
		{
			input.append(" THE_END");

			//cout << input << endl;

			//cout << "entered CreatMap Function" << endl;
			stringstream ss(input);
			string word;
			vector<string> allword;
			string prefix1;
			string prefix2;
			string suffix;
			string prefix;
			int index;

			ss>>prefix1;
			ss>>prefix2;

			while (ss>>word)
			{
			//allword.push_back(word);
			//if (word=="THE_END"){break;}
			//}
			
			//for(int i=0; i<allword.size()-1; i++)
			//{
			prefix = prefix1 + " " + prefix2;
			suffix = word;

	//		cout << "prefix is" << prefix << endl;
		//	cout << "sufix is" << suffix << endl;


			index = Duplicate(prefix);
			
//			cout << "index is" << index << endl;

			if (index==Prefix.size())
			{
			//cout << "prefix is" << prefix << endl;
			
			Pair npair(prefix, suffix);
			Prefix.push_back(npair);

			//Prefix.push_back(prefix);
			//Suffix.push_back(suffix);
		
			}
			else if(prefix == (Prefix[index].Key)){
			Prefix[index].Suffix.push_back(suffix);
			
			}
			prefix1=prefix2;
			prefix2=word;


			}
			return;
		}

		/**
		 * getSuffixList
		 *
		 * Returns the list of suffixes associated with the given prefix.
		 * Returns an empty vector if the given prefix is not in the map or no
		 * map has been created yet.
		 *
		 * @param prefix
		 * 		the prefix to be found
		 * @return a list of suffixes associated with the given prefix if the
		 * 		prefix is found; an empty vector otherwise
		 */
		vector<string> Mimic::getSuffixList(string prefix)
		{
		//	cout << "entered Get SuffixList Function" << endl;
		
			int eye=0;

			for(int i =0; i<Prefix.size() ; i++)
			{
				if (prefix== Prefix[i].Key)
				{
				return Prefix[i].Suffix;
				}
				eye = i;
			}
			return Prefix[eye].Suffix;
		}

		//Part 2--------------------------------------------------------------
		/**
		 * generateText
		 *
		 * Generates random text using the map created by the createMap method.
		 *
		 * To generate the new text, start with the first prefix that was read
		 * and randomly select one of the suffixes associated with that prefix.
		 * The next prefix is the second word from the previous prefix and the
		 * selected suffix. Continue selecting random suffixes and building the
		 * next prefix until the suffix "THE_END" is selected. The token
		 * "THE_END" should not be returned as part of your generated text.
		 *
		 * @return random text generated using the map created with the sample
		 * 		text; an empty string if no map has been created yet
		 */
		string Mimic::generateText()
		{
			stringstream ss(Prefix[0].Key);
			string sentence ="";
			string random;
			string first;
			string second;
			//int randomNum;
			srand(time(0));
			string key;
			string both = "";
			int z;
			ss >> first;
			ss >> second;
			key = first + " " + second;

			sentence = "";
	//		cout << "first is "<< first << endl;
					//cout << "second is "<< second << endl;
						//	cout << "sentence is "<< sentence << endl;

							sentence += key;

			while (random != "THE_END")
			{
				
				int z = Duplicate(key);
				random = Prefix[z].Suffix[rand() % Prefix[z].Suffix.size()];
				if(random== "THE_END"){break;}
				sentence += " " + random;

				first = second;
				second = random;
				key = first + " " + second;
				both = " " + first + " " + second;

				//cout << "first is "<< first << endl;
					//cout << "second is "<< second << endl;
							//cout << "sentence is "<< sentence << endl;

				if(random== "THE_END"){break;}

				//sentence += " " + random;

				//cout << "first is "<< first << endl;
					//cout << "second is "<< second << endl;
					//		cout << "sentence is "<< sentence << endl;

				

				
			}
			return sentence;
		}