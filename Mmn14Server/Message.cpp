#include "Message.h"

int GetRequestHeader(char*, int len, RequestHeader* out_requst_header) 
{
	return 1;



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