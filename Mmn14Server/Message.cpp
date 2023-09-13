#include "Message.h"
#include <malloc.h>
#include <iostream>

bool GetRequestHeader(char* buff, int buff_len, RequestHeader* out_requst_header, int* out_bytes_consumed)
{
	bool NoError = true;
	int BytesConsumed = 0;
	if (buff_len >= sizeof(RequestHeader))
	{
		RequestHeader* LocalReqHeader = new RequestHeader;
		if (IsLittleEndian())// in case of little endian system
		{//read start of header
			std::memcpy(buff, &(LocalReqHeader->_user_id), sizeof(LocalReqHeader->_user_id));//set id
			BytesConsumed += sizeof(LocalReqHeader->_user_id);
			std::memcpy(buff, &(LocalReqHeader->_version), sizeof(LocalReqHeader->_version));//set version
			BytesConsumed += sizeof(LocalReqHeader->_version);
			std::memcpy(buff, &(LocalReqHeader->_op), sizeof(LocalReqHeader->_op));//set op
			BytesConsumed += sizeof(LocalReqHeader->_op);
			if (OpHasNameField(LocalReqHeader->_op))//Check if to read name field or if request header ends here
			{
				if (LocalReqHeader->_name_len > MAX_FILE_NAME_LENGTH)//In case of invalid name length
				{
					NoError = false;
				}

				else if (buff_len - BytesConsumed > sizeof(LocalReqHeader->_name_len))
				{
					std::memcpy(buff, &(LocalReqHeader->_name_len), sizeof(LocalReqHeader->_name_len));//set name legnth
					BytesConsumed += sizeof(LocalReqHeader->_name_len);
					if (buff_len - BytesConsumed == LocalReqHeader->_name_len)
					{
						LocalReqHeader->_file_name = (char*)malloc(LocalReqHeader->_name_len);
						if (LocalReqHeader->_file_name != nullptr)
						{
							std::memcpy(LocalReqHeader->_file_name, buff + BytesConsumed, LocalReqHeader->_name_len);
						}
						else
						{
							std::cerr << "Error: Couldn't allocate memory for header name length" << std::endl;
							free(LocalReqHeader->_file_name);//Todo change for safe free
							LocalReqHeader->_file_name = nullptr;
							NoError = false;
						}
					}
					else
					{
						std::cerr << "Error: Couldn't allocate memory for header name length" << std::endl;
						NoError = false;
					}
				}
				else//in case Reading in end of buffer, report of bytesRead
				{

				}
			}
			else //in case of no name in request header
			{
				NoError = true;
			}
		}
		else
		{//TODO handle big endianes,



		}


	}
	*out_bytes_consumed = BytesConsumed;
	return NoError;
}

//
//message_parse_position GetRequestHeader(char* buffer, int buf_len, int* out_BytesConsumed, RequestHeader* out_requst_header,)
//{
//	//int BytesConsumed = 0;
//	//if (buf_len >= sizeof(RequestHeader))
//	//{
//	//	RequestHeader* LocalReqHeader = new RequestHeader;
//	//	if (IsLittleEndian())
//	//	{
//	//		std::memcpy(buffer, &(LocalReqHeader->_user_id), sizeof(LocalReqHeader->_user_id));//set id
//	//		BytesConsumed += sizeof(LocalReqHeader->_user_id);
//	//		std::memcpy(buffer, &(LocalReqHeader->_version), sizeof(LocalReqHeader->_version));//set version
//	//		BytesConsumed += sizeof(LocalReqHeader->_version);
//	//		std::memcpy(buffer, &(LocalReqHeader->_op), sizeof(LocalReqHeader->_op));//set op
//	//		BytesConsumed += sizeof(LocalReqHeader->_op);
//	//		switch (LocalReqHeader->_op)
//	//		{
//	//		case r_get_file:
//	//		case r_delete_file:
//	//			std::memcpy(buffer, &(LocalReqHeader->_name_len), sizeof(LocalReqHeader->_name_len));
//	//			BytesConsumed += sizeof(LocalReqHeader->_name_len);
//	//			if (buf_len - BytesConsumed >= LocalReqHeader->_name_len)
//	//			{
//
//	//			};
//	//			break;
//	//		case r_Backup_file:
//
//	//			break;
//	//		default:
//	//			//cerr:: here or maybe throw exception
//	//			break;
//	//		}
//	//	}
//
//
//	//	out_requst_header = LocalReqHeader;
//	//}
//	//*out_BytesConsumed = BytesConsumed;
//}

bool OpHasNameField(op _op)
{
	bool RetHasName = true;
	switch (_op)
	{
	case r_Backup_file:
		RetHasName = true;
		break;
	case r_get_file:
		RetHasName = true;
		break;
	case r_delete_file:
		RetHasName = true;
		break;
	case r_list_files:
		RetHasName = false;
		break;
	default:
		break;
	}
	return RetHasName;
}