//
// VMime library (http://vmime.sourceforge.net)
// Copyright (C) 2002-2004 Vincent Richard <vincent@vincent-richard.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef VMIME_MESSAGEBUILDER_HPP_INCLUDED
#define VMIME_MESSAGEBUILDER_HPP_INCLUDED


#include "base.hpp"

#include "mailbox.hpp"
#include "addressList.hpp"
#include "text.hpp"
#include "message.hpp"
#include "mediaType.hpp"
#include "attachment.hpp"
#include "textPart.hpp"
#include "bodyPart.hpp"


namespace vmime
{


/** A helper for building MIME messages.
  */

class messageBuilder
{
public:

	messageBuilder();
	~messageBuilder();

public:

	/** Return the expeditor of the message (From:).
	  *
	  * @return expeditor of the message
	  */
	const mailbox& getExpeditor() const;

	/** Set the expeditor of the message (From:).
	  *
	  * @param expeditor expeditor of the message
	  */
	void setExpeditor(const mailbox& expeditor);

	/** Return the recipients of the message (To:).
	  *
	  * return recipients of the message
	  */
	const addressList& getRecipients() const;

	/** Return the recipients of the message (To:).
	  *
	  * return recipients of the message
	  */
	addressList& getRecipients();

	/** Set the recipients of the message (To:).
	  *
	  * @param recipients list of recipients
	  */
	void setRecipients(const addressList& recipients);

	/** Return the copy recipients of the message (Cc:).
	  *
	  * @return copy recipients of the message
	  */
	const addressList& getCopyRecipients() const;

	/** Return the copy recipients of the message (Cc:).
	  *
	  * @return copy recipients of the message
	  */
	addressList& getCopyRecipients();

	/** Set the copy recipients of the message (Cc:).
	  *
	  * @param cc list of copy recipients
	  */
	void setCopyRecipients(const addressList& cc);

	/** Return the blind-copy recipients of the message (Bcc:).
	  *
	  * @return blind-copy recipients of the message
	  */
	const addressList& getBlindCopyRecipients() const;

	/** Return the blind-copy recipients of the message (Bcc:).
	  *
	  * @return blind-copy recipients of the message
	  */
	addressList& getBlindCopyRecipients();

	/** Set the blind-copy recipients of the message (Bcc:).
	  *
	  * @param bcc list of blind-copy recipients
	  */
	void setBlindCopyRecipients(const addressList& bcc);

	/** Return the subject of the message.
	  *
	  * @return subject of the message
	  */
	const text& getSubject() const;

	/** Set the subject of the message.
	  *
	  * @param subject message subject
	  */
	void setSubject(const text& subject);

	/** Attach a new object to the message.
	  *
	  * @param attach new attachment
	  */
	void attach(attachment* attach);

	/** Remove the attachment at the specified position.
	  *
	  * @param pos position of the attachment to remove
	  */
	void removeAttachment(const int pos);

	/** Return the attachment at the specified position.
	  *
	  * @param pos position of the attachment
	  * @return attachment at the specified position
	  */
	const attachment* getAttachmentAt(const int pos) const;

	/** Return the attachment at the specified position.
	  *
	  * @param pos position of the attachment
	  * @return attachment at the specified position
	  */
	attachment* getAttachmentAt(const int pos);

	/** Return the number of attachments in the message.
	  *
	  * @return number of attachments
	  */
	const int getAttachmentCount() const;

	/** Return the list of attachments.
	  *
	  * @return list of attachments
	  */
	const std::vector <const attachment*> getAttachmentList() const;

	/** Return the list of attachments.
	  *
	  * @return list of attachments
	  */
	const std::vector <attachment*> getAttachmentList();

	/** Change the type of the text part and construct a new part.
	  *
	  * @param type media type of the text part
	  */
	void constructTextPart(const mediaType& type);

	/** Return the text part of the message.
	  *
	  * @return text part of the message
	  */
	textPart* getTextPart();

	/** Construct a new message based on the information specified
	  * in this object.
	  *
	  * @return a new message
	  */
	message* construct() const;

private:

	mailbox m_from;

	addressList m_to;
	addressList m_cc;
	addressList m_bcc;

	text m_subject;

	textPart* m_textPart;

	std::vector <attachment*> m_attach;
};


} // vmime


#endif // VMIME_MESSAGEBUILDER_HPP_INCLUDED
