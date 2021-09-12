// Logger standard header
#include <fstream>
#include<iostream>
#include<time.h>
#include <string>
#include <string>


class Logger
{

	private:
		void writer(FILE* fp, const char * filename, const char * mode , errno_t error , struct tm nowtime,const char * text,const char * mode_d) {

			if (fopen_s(&fp, filename, mode) != 0) {
				//ファイルを開けなかったとき
				if (error != 0) {
					//書き出し不可のとき
				}
			}
			else {
				fprintf(fp, "[%s %d-%d-%d-%d-%d-%d] %s",mode_d , nowtime.tm_year + 1900, nowtime.tm_mon + 1, nowtime.tm_mday,
					nowtime.tm_hour, nowtime.tm_min,nowtime.tm_sec, text);
				fclose(fp);
			}

		}

	public:
		void debug(const char* filename, const char* mode, const char* text) {

			FILE fp;
			time_t jikan = time(NULL);
			struct tm nowtime;
			errno_t error = localtime_s(&nowtime, &jikan);

			writer(
				&fp,
				filename,
				mode,
				error,
				nowtime,
				text,
				"DEBUG"

			);

			return;
		};

	public:
		void info(const char* filename, const char* mode, const char* text) {

			FILE fp;
			time_t jikan = time(NULL);
			struct tm nowtime;
			errno_t error = localtime_s(&nowtime, &jikan);

			writer(
				&fp,
				filename,
				mode,
				error,
				nowtime,
				text,
				"INFO"

			);

			return;
		};

	public:
		void warn(const char* filename, const char* mode, const char* text) {

			FILE fp;
			time_t jikan = time(NULL);
			struct tm nowtime;
			errno_t error = localtime_s(&nowtime, &jikan);

			writer(
				&fp,
				filename,
				mode,
				error,
				nowtime,
				text,
				"WARN"

			);

			return;
		};
};