const bcrypt = require('bcryptjs');

const gen_rand_str = (length) => {
    const characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    let result = '';
    for (let i = 0; i < length; i++) {
        const randomIndex = Math.floor(Math.random() * characters.length);
        result += characters.charAt(randomIndex);
    }
    return result;
}

const get_secret = () => {
    let secret = process.env.SECRET;
    if (secret == undefined)
        return "NULL";
    return secret;
}

const gen_hash = async (password) => {
    try {
        const hash = await bcrypt.hash(password, '$2b$10$123456789012345678901.');
        return hash;
    } catch (error) {
        console.error('Error hashing password:', error);
        throw error;
    }
};

const is_num = (value) => {
    return /^-?\d+$/.test(value);
}

const is_email = (input) => {
    const email_reg = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return email_reg.test(input);
}

const is_password_secure = (input) => {
    const minLength = 8;
    const hasUpperCase = /[A-Z]/.test(input);
    const hasLowerCase = /[a-z]/.test(input);
    const hasNumber = /[0-9]/.test(input);
    const hasSpecialChar = /[!@#$%^&*]/.test(input);
    const isLongEnough = input.length >= minLength;
    const hasRequiredCharacters = hasUpperCase && hasLowerCase && hasNumber && hasSpecialChar;
    return isLongEnough && hasRequiredCharacters;
  }

module.exports = {
    gen_rand_str,
    get_secret,
    gen_hash,
    is_num,
    is_email,
    is_password_secure,
};
